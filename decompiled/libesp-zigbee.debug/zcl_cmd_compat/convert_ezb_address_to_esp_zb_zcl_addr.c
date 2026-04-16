/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> convert_ezb_address_to_esp_zb_zcl_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void convert_ezb_address_to_esp_zb_zcl_addr(esp_zb_zcl_addr_t *dst,ezb_address_t *src)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  
  dst->addr_type = src->addr_mode;
  uVar1 = *(uint8_t *)((int)&src->u + 1);
  uVar2 = *(uint8_t *)((int)&src->u + 2);
  uVar3 = *(uint8_t *)((int)&src->u + 3);
  uVar4 = *(uint8_t *)((int)&src->u + 4);
  uVar5 = *(uint8_t *)((int)&src->u + 5);
  uVar6 = *(uint8_t *)((int)&src->u + 6);
  uVar7 = *(uint8_t *)((int)&src->u + 7);
  (dst->u).ieee_addr[0] = *(uint8_t *)&src->u;
  (dst->u).ieee_addr[1] = uVar1;
  (dst->u).ieee_addr[2] = uVar2;
  (dst->u).ieee_addr[3] = uVar3;
  (dst->u).ieee_addr[4] = uVar4;
  (dst->u).ieee_addr[5] = uVar5;
  (dst->u).ieee_addr[6] = uVar6;
  (dst->u).ieee_addr[7] = uVar7;
  return;
}

