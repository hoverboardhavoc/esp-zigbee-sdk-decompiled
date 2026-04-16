/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_extaddr_decompress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_extaddr_decompress(ezb_extaddr_t *extaddr,nwk_extaddr_c_t *extaddr_c)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  nwk_oui_t *pauVar5;
  
  pauVar5 = oui_table_get_oui(extaddr_c->oui_ref);
  uVar1 = extaddr_c->device_id[1];
  uVar2 = extaddr_c->device_id[2];
  uVar3 = extaddr_c->device_id[3];
  uVar4 = extaddr_c->device_id[4];
  (extaddr->field_0).u8[0] = extaddr_c->device_id[0];
  (extaddr->field_0).u8[1] = uVar1;
  (extaddr->field_0).u8[2] = uVar2;
  (extaddr->field_0).u8[3] = uVar3;
  (extaddr->field_0).u8[4] = uVar4;
  (extaddr->field_0).u8[5] = (*pauVar5)[0];
  (extaddr->field_0).u8[6] = (*pauVar5)[1];
  (extaddr->field_0).u8[7] = (*pauVar5)[2];
  return;
}

