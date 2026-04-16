/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> parse_summation_from_payload
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
  uint uVar1;
  uint __nmemb;
  uint64_t *puVar2;
  int iVar3;
  undefined3 in_register_00002031;
  
  __nmemb = CONCAT31(in_register_00002031,num);
  if (__nmemb != 0) {
    puVar2 = (uint64_t *)calloc(__nmemb,8);
    *summation = puVar2;
    if (puVar2 == (uint64_t *)0x0) {
      __nmemb = 0x89;
    }
    else {
      for (uVar1 = 0; uVar1 < __nmemb; uVar1 = uVar1 + 1 & 0xff) {
        iVar3 = zcl_packet_read_variable_attr_value(payload,offset,0x25,*summation + uVar1);
        if (iVar3 != 6) {
          __nmemb = 0x80;
          goto _L0;
        }
      }
      __nmemb = 0;
    }
  }
_L0:
  return (ezb_zcl_status_t)__nmemb;
}

