/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> read_zcl_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
read_zcl_string(zcl_packet_payload_t *payload,uint16_t *offset,uint8_t *string,uint8_t max_length)

{
  byte *unaff_s0;
  ezb_zcl_status_t eVar1;
  uint16_t *extraout_a1;
  undefined3 in_register_00002035;
  uint uVar2;
  uint16_t *unaff_s2;
  
  uVar2 = CONCAT31(in_register_00002035,max_length);
  if (((payload == (zcl_packet_payload_t *)0x0) || (unaff_s2 = offset, offset == (uint16_t *)0x0))
     || (unaff_s0 = string, string == (uint8_t *)0x0)) {
    uVar2 = 0;
    string = (uint8_t *)0x0;
    payload = (zcl_packet_payload_t *)__assert_func(0,0);
    offset = extraout_a1;
  }
  af_read_le8(payload,offset,string);
  eVar1 = 0x87;
  if (*unaff_s0 < uVar2) {
    af_read_bytes(payload,unaff_s2,(ushort)*unaff_s0,unaff_s0 + 1);
    eVar1 = '\0';
  }
  return eVar1;
}

