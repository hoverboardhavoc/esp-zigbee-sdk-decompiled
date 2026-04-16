/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> basic.o -> basic_cluster_reset_to_factory_default_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
basic_cluster_reset_to_factory_default_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  
  if (packet == (zcl_packet_t *)0x0) {
    eVar1 = 0xfe;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    eVar1 = 0xfe;
  }
  else {
    eVar1 = zcl_message_basic_reset_to_factory_default(packet);
    eVar1 = zcl_packet_setup_default_response(rsp,packet,eVar1);
  }
  return eVar1;
}

