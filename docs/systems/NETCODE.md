# NETCODE — protocol, messages, session

Status: 🔶 message layer decoded (single-player + MP); transport + dpnet server layer open.

**Evidence:** corpus (`comm_msg_dispatch @ 0x00531470`, the 36.9 KB packet switch),
`comm_players_state_send @ 0x0052EF00`, `comm_echo_send @ 0x0052E1F0`,
`comm_socket_sendto/recv_loop`, ecosystem server `giantsd`/`gckmsd`. **Derived** unless
noted.

## Transport

- `WS2_32.dll` is imported statically; message handlers call
  `comm_socket_sendto`/`comm_socket_recv_loop` (UDP-style datagrams).
- `comm_echo_send @ 0x0052E1F0`: `sprintf("\\echo %s", msg)` → sendto (len < 0x547) —
  LAN discovery/echo (this is the DirectPlay-era `\echo\` protocol surface; the
  `giantsd`/`gckmsd` servers speak the same envelope). *Inferred*: exact session
  negotiation lives behind the `comm_00426540` / `comm_socket_*` family — open item.
- Lobby/GameSpy: `gamespy_host_game` (called from `dlog_audio_options_process` flow),
  `comm_player_join_check`, `session_list_build`-family dialogs.

## The message layer (authoritative for a reimplementation)

`comm_msg_dispatch @ 0x00531470` — the receive pump: a giant switch over the packet
type byte, buffer pointer `DAT_005E0304` advancing per message. Confirmed handlers
(named in w227/w228/w230):

| type | handler | payload |
|---|---|---|
| 0x17 | `comm_msg17_pair_send` | pair order (attacker/victim ids + f32 + param) |
| 0x1A | `comm_msg1a_id_send` | notify id (bubble/chat attach) |
| 0x1C/0x1D/0x29 | `comm_orders_dispatch` | group orders: spread / repair — routed to owner by `+0x188` |
| 0x25 | `mecc_chat_send_25` | chat line |
| 0x31 | `comm_players_state_send` | player state broadcast (active flag, flags byte) |
| 0x5C | `comm_scores_send` | ushort score list (clamped 0–999, max `DAT_632F34` players) |
| '1'/'2'/'F'/'G' | inline cases | team broadcast draw, world ripple, player marker size, fakehost menu |
| pos/chat | `comm_pos_send` / `comm_chat_send_1/2` | position broadcast (`+0xA0/a4/a8 + +0xC8`), chat |
| world sync | `comm_session_state_pack @ 0x00529C00` | packs `{state<<8\|flags…, world_id}` + bitfield (f1c/f20/f38 flags) |
| player mgmt | `comm_player_slot_clear`, `comm_player_flags_set_all/get`, `comm_player_active_get`, `comm_player_ready_set` | 20-player slot table `DAT_5DDFC0` (0x20 stride) + `DAT_5DDF60`/`5DE290`/`5DE2A4` status arrays |

Player-state readiness flow: `comm_all_players_ready` (state-gated), 
`comm_all_players_loaded` (every player byte `DAT_5DE290 >= 0xC`).

## Session state machine

`DAT_00632F18` = game state (0–3 = menus/lobby, 6–7 = MP in-game excluded gates in
`comm_all_players_*`), `DAT_00632F34` = max players (20), `DAT_00632F44` = current
player count (`net_active_players_get`).

## Validation

- Single-player: the dispatcher still runs (`comm_heartbeat_send`,
  `comm_game_session_update` in `game_loop_run`) — a trace during solo play captures
  the keepalive cadence.
- MP parity target: the `giantsd`/`gckmsd` servers (open-source, in
  `RESSOURCES_FOR_AI/git_repos_from_amazed/`) double as a reference client/server pair;
  `comm_echo_send` gives the first byte-level test vector.
