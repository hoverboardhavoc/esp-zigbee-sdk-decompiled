/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> append_summation_to_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
append_summation_to_payload(zcl_packet_payload_t *payload,uint8_t num,uint64_t *summation)

{
  uint64_t *puVar1;
  ezb_zcl_status_t eVar2;
  int iVar3;
  undefined3 in_register_0000202d;
  
  if ((CONCAT31(in_register_0000202d,num) == 0) || (eVar2 = '\x01', summation != (uint64_t *)0x0)) {
    puVar1 = summation + CONCAT31(in_register_0000202d,num);
    do {
      if (summation == puVar1) {
        return '\0';
      }
      iVar3 = zcl_packet_append_variable_attr_value(payload,0x25,summation);
      summation = summation + 1;
    } while (iVar3 == 0);
    eVar2 = 0x89;
  }
  return eVar2;
}

