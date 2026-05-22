/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> time_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void time_cluster_srv_write_attr_hook
               (uint8_t ep_id,uint16_t attr_id,void *new_value,uint16_t manuf_code)

{
  zcl_attr_desc_t *pzVar1;
  ezb_zcl_time_interface_t *peVar2;
  undefined2 in_register_0000202e;
  
  if (CONCAT22(in_register_0000202e,attr_id) == 0) {
    pzVar1 = time_server_get_attr_desc(ep_id,8);
    if ((pzVar1 != (zcl_attr_desc_t *)0x0) && ((undefined4 *)pzVar1->data_p != (undefined4 *)0x0)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined4 *)pzVar1->data_p = *new_value;
    }
    peVar2 = time_server_get_interface(ep_id);
    if (peVar2->set_utc_time == (_func_void_uint32_t *)0x0) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/time.c",0x116,
                    "time_cluster_srv_write_attr_hook","interface->set_utc_time != ((void *)0)");
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Load size is inaccurate */
    (*peVar2->set_utc_time)(*new_value);
  }
  return;
}

