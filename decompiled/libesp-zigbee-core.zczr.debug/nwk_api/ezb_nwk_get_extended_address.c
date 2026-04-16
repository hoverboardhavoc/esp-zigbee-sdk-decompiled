/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_api.o -> ezb_nwk_get_extended_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_nwk_get_extended_address(ezb_extaddr_t *extaddr)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  uint8_t *puVar8;
  
  puVar8 = (uint8_t *)nwk_get_extended_address();
  uVar1 = puVar8[1];
  uVar2 = puVar8[2];
  uVar3 = puVar8[3];
  uVar4 = puVar8[4];
  uVar5 = puVar8[5];
  uVar6 = puVar8[6];
  uVar7 = puVar8[7];
  (extaddr->field_0).u8[0] = *puVar8;
  (extaddr->field_0).u8[1] = uVar1;
  (extaddr->field_0).u8[2] = uVar2;
  (extaddr->field_0).u8[3] = uVar3;
  (extaddr->field_0).u8[4] = uVar4;
  (extaddr->field_0).u8[5] = uVar5;
  (extaddr->field_0).u8[6] = uVar6;
  (extaddr->field_0).u8[7] = uVar7;
  return;
}

