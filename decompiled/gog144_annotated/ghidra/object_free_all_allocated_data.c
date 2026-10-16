
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* PS2 candidate: object_free_all_allocated_data (conf 0.468) */

void object_free_all_allocated_data(OBJECT *obj)

{
  dword dVar1;
  
  if ((((int)obj->state < 0x6b) && (*(code **)(&DAT_0055cb28 + obj->state * 0x44) != (code *)0x0))
     && (obj->animate_state != 0)) {
    (**(code **)(&DAT_0055cb28 + obj->state * 0x44))(obj);
  }
  if (obj->animate_state != 0) {
    mem_free_tagged(obj->animate_state,s_C__Giants_source_main_objspec_c_0055e774,0xf9);
    obj->animate_state = 0;
  }
  dVar1 = obj->alloc_data2;
  if ((dVar1 != 0) && (*(char *)(dVar1 + 0x1e) < '\0')) {
    main_00508840(dVar1);
    texture_destroy(obj->alloc_data2);
    mem_free_tagged(obj->alloc_data2,s_C__Giants_source_main_objspec_c_0055e774,0xbb);
  }
  obj->alloc_data2 = 0;
  obj->pad_104 = 0;
  collgrid_clear_grid(obj);
  if (obj->alloc_data1 != 0) {
    mem_free_tagged(obj->alloc_data1,s_C__Giants_source_main_objspec_c_0055e774,0xe1);
  }
  obj->alloc_data1 = 0;
  obj->alloc_data0 = 0;
  return;
}

