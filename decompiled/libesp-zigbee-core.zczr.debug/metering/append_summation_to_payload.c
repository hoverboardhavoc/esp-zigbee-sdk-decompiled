/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> append_summation_to_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
append_summation_to_payload(zcl_packet_payload_t *payload,uint8_t num,uint64_t *summation)

{
  uint uVar1;
  int iVar2;
  undefined3 in_register_0000202d;
  
  if (CONCAT31(in_register_0000202d,num) == 0) {
    uVar1 = 0;
  }
  else {
    if (summation == (uint64_t *)0x0) {
      return '\x01';
    }
    uVar1 = 0;
  }
  while( true ) {
    if (CONCAT31(in_register_0000202d,num) <= uVar1) {
      return '\0';
    }
    iVar2 = zcl_packet_append_variable_attr_value(payload,0x25,summation + uVar1);
    if (iVar2 != 0) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return 0x89;
}

