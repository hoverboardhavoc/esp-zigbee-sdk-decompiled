/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> ezb_zcl_time_server_interface_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ezb_err_t ezb_zcl_time_server_interface_register(uint8_t ep_id,ezb_zcl_time_interface_t interface)

{
  ezb_zcl_time_interface_t *peVar1;
  ezb_err_t eVar2;
  _func_uint32_t *in_a1;
  _func_void_uint32_t *in_a2;
  ezb_zcl_time_interface_t interface_local;
  
  if (in_a1 == (_func_uint32_t *)0x0) {
    eVar2 = 2;
  }
  else if (in_a2 == (_func_void_uint32_t *)0x0) {
    eVar2 = 2;
  }
  else {
    peVar1 = time_server_get_interface(ep_id);
    if (peVar1 == (ezb_zcl_time_interface_t *)0x0) {
      eVar2 = 5;
    }
    else {
      peVar1->get_utc_time = in_a1;
      peVar1->set_utc_time = in_a2;
      eVar2 = 0;
    }
  }
  return eVar2;
}

