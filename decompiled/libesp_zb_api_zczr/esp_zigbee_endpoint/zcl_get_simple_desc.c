/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_endpoint.o -> zcl_get_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * zcl_get_simple_desc(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined1 *puVar5;
  uint uVar6;
  void *__ptr;
  undefined1 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 uStack_28;
  undefined1 uStack_25;
  undefined1 uStack_24;
  
  bVar1 = param_2[2];
  uVar9 = (uint)bVar1;
  bVar2 = param_2[3];
  if (param_1 == 0) {
    uVar8 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar8,0x10000,"zcl_get_simple_desc",0x4b);
    puVar7 = (undefined1 *)0x0;
  }
  else {
    __ptr = malloc(0xc);
    puVar7 = (undefined1 *)realloc(__ptr,(uVar9 + bVar2 + 4) * 2);
    uStack_28 = (undefined1)param_3;
    *puVar7 = uStack_28;
    puVar7[1] = (char)((uint)param_3 >> 8);
    puVar7[2] = (char)((uint)param_3 >> 0x10);
    uStack_25 = (undefined1)((uint)param_3 >> 0x18);
    uStack_24 = (undefined1)param_4;
    puVar7[3] = uStack_25;
    puVar7[4] = uStack_24;
    bVar4 = (byte)((uint)param_4 >> 8) & 0xf;
    puVar7[5] = puVar7[5] & 0xf0 | bVar4;
    puVar7[5] = bVar4;
    puVar7[6] = bVar1;
    puVar7[7] = bVar2;
    uVar10 = 0;
    for (uVar6 = 0; uVar6 < *param_2; uVar6 = uVar6 + 1 & 0xff) {
      puVar5 = (undefined1 *)(uVar6 * 0xf + param_1);
      if (puVar5[8] == '\x01') {
        uVar3 = puVar5[1];
        puVar7[uVar10 * 2 + 8] = *puVar5;
        puVar7[uVar10 * 2 + 9] = uVar3;
        uVar10 = uVar10 + 1 & 0xff;
      }
      else if (puVar5[8] == '\x02') {
        uVar3 = puVar5[1];
        puVar7[uVar9 * 2 + 8] = *puVar5;
        puVar7[uVar9 * 2 + 9] = uVar3;
        uVar9 = uVar9 + 1 & 0xff;
      }
      else {
        uVar8 = esp_log_timestamp();
        esp_log_write(2,0x10000,&_LC5,uVar8,0x10000,puVar5[8]);
      }
    }
  }
  return puVar7;
}

