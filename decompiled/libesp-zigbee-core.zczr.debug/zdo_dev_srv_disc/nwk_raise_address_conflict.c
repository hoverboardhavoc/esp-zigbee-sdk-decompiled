/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> nwk_raise_address_conflict
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_raise_address_conflict(ezb_shortaddr_t offending_addr)

{
  undefined4 uStack_14;
  nwk_network_status_cmd_t cmd;
  
  uStack_14 = (uint)CONCAT21(offending_addr,0xd);
  nwk_send_status(0xfffd,&uStack_14);
  nwk_handle_network_status_local(&uStack_14);
  return;
}

