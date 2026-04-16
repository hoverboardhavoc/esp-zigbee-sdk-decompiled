/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> time_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void time_cluster_srv_write_attr_hook
               (uint8_t ep_id,uint16_t attr_id,void *new_value,uint16_t manuf_code)

{
  zcl_attr_desc_t *pzVar1;
  ezb_zcl_time_interface_t *peVar2;
  undefined2 in_register_0000202e;
  _func_void_uint32_t *UNRECOVERED_JUMPTABLE;
  
  if (CONCAT22(in_register_0000202e,attr_id) == 0) {
    pzVar1 = time_server_get_attr_desc(ep_id,8);
    if ((pzVar1 != (zcl_attr_desc_t *)0x0) && ((undefined4 *)pzVar1->data_p != (undefined4 *)0x0)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined4 *)pzVar1->data_p = *new_value;
    }
    peVar2 = time_server_get_interface(ep_id);
    UNRECOVERED_JUMPTABLE = peVar2->set_utc_time;
    if (UNRECOVERED_JUMPTABLE == (_func_void_uint32_t *)0x0) {
      __assert_func(0,0,0,0);
    }
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Could not recover jumptable at 0x00010240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(*new_value);
    return;
  }
  return;
}

