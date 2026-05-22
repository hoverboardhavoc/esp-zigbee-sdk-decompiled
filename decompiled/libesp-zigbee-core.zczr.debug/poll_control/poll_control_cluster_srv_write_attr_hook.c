/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void poll_control_cluster_srv_write_attr_hook
               (uint8_t endpoint,uint16_t attr_id,void *new_value,uint16_t manuf_code)

{
  undefined2 in_register_0000202e;
  int iVar1;
  undefined2 in_register_00002036;
  int in_a4;
  
  iVar1 = CONCAT22(in_register_0000202e,attr_id);
  if (new_value == (void *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/poll_control.c",0x149,
                  "poll_control_cluster_srv_write_attr_hook","new_value");
  }
  else {
                    /* WARNING: Load size is inaccurate */
    in_a4 = *new_value;
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        nwk_pim_set_fast_poll_interval(in_a4 * 0xfa,CONCAT22(in_register_00002036,manuf_code));
        return;
      }
      if (iVar1 != 0) {
        return;
      }
      poll_control_check_in_stop(endpoint);
      poll_control_check_in_start(endpoint);
      return;
    }
  }
  nwk_ed_set_keepalive_interval(in_a4 * 0xfa);
  return;
}

