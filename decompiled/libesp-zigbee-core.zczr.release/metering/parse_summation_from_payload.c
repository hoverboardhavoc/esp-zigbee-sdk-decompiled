/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> parse_summation_from_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
parse_summation_from_payload
          (zcl_packet_payload_t *payload,uint16_t *offset,uint8_t num,uint64_t **summation)

{
  size_t sVar1;
  ezb_zcl_status_t eVar2;
  uint64_t *puVar3;
  int iVar4;
  undefined3 in_register_00002031;
  size_t __nmemb;
  
  __nmemb = CONCAT31(in_register_00002031,num);
  if (__nmemb == 0) {
    return '\0';
  }
  puVar3 = (uint64_t *)calloc(__nmemb,8);
  *summation = puVar3;
  eVar2 = 0x89;
  if (puVar3 != (uint64_t *)0x0) {
    sVar1 = 0;
    do {
      iVar4 = zcl_packet_read_variable_attr_value(payload,offset,0x25,*summation + sVar1);
      if (iVar4 != 6) {
        return 0x80;
      }
      sVar1 = sVar1 + 1;
    } while (__nmemb != sVar1);
    eVar2 = '\0';
  }
  return eVar2;
}

