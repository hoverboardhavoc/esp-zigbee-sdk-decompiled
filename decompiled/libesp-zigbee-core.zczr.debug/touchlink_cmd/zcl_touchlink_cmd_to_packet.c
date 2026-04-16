/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_cmd_to_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_touchlink_cmd_to_packet
                    (zcl_packet_t *packet,uint8_t direction,uint8_t command_id,
                    ezb_address_t *dst_addr)

{
  ezb_err_t eVar1;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  undefined1 *in_a3;
  
  if (packet == (zcl_packet_t *)0x0) {
    eVar1 = 2;
  }
  else {
    zcl_packet_setup_header
              (1,0,CONCAT31(in_register_0000202d,direction),0,
               CONCAT31(in_register_00002031,command_id));
    zcl_packet_setup_stamp(packet,0,0,0x1000,0xc05e,*in_a3,in_a3 + 2);
    zcl_packet_add_payload(packet,0,0);
    eVar1 = 0;
  }
  return eVar1;
}

