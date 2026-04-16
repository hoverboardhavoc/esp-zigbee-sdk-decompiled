/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> time_server_get_interface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_time_interface_t * time_server_get_interface(uint8_t ep_id)

{
  ezb_zcl_time_interface_t *peVar1;
  undefined3 in_register_00002029;
  
  time_server_get_time_ctx(ep_id);
  peVar1 = (ezb_zcl_time_interface_t *)
           ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),10,1,0xeffe,0x131b);
  if (peVar1 != (ezb_zcl_time_interface_t *)0x0) {
    peVar1 = (ezb_zcl_time_interface_t *)peVar1[1].get_utc_time;
  }
  return peVar1;
}

