/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> zcl_get_attr_lists
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * zcl_get_attr_lists(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  char cVar8;
  undefined1 *puVar9;
  void *pvVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined1 *puVar13;
  int iVar14;
  
  if (param_1 == 0) {
    uVar11 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_L0,uVar11,"ESP_ZIGBEE_API_CORE");
    pvVar10 = (void *)0x0;
  }
  else {
    cVar8 = '\0';
    iVar14 = param_1;
    while (iVar14 = *(int *)(iVar14 + 0xc), iVar14 != 0) {
      cVar8 = cVar8 + '\x01';
    }
    if (cVar8 == '\0') {
      uVar11 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_API_CORE",&_LC4,uVar11,"ESP_ZIGBEE_API_CORE");
      pvVar10 = (void *)0x0;
    }
    else {
      zcl_finish_attr_lists();
      puVar9 = *(undefined1 **)(param_1 + 0xc);
      pvVar10 = calloc((uint)(byte)(cVar8 + 1),8);
      for (uVar12 = 0; uVar12 < (byte)(cVar8 + 1); uVar12 = uVar12 + 1 & 0xff) {
        puVar13 = (undefined1 *)(uVar12 * 8 + (int)pvVar10);
        uVar1 = puVar9[1];
        uVar2 = puVar9[2];
        uVar3 = puVar9[3];
        uVar4 = puVar9[4];
        uVar5 = puVar9[5];
        uVar6 = puVar9[6];
        uVar7 = puVar9[7];
        *puVar13 = *puVar9;
        puVar13[1] = uVar1;
        puVar13[2] = uVar2;
        puVar13[3] = uVar3;
        puVar13[4] = uVar4;
        puVar13[5] = uVar5;
        puVar13[6] = uVar6;
        puVar13[7] = uVar7;
        puVar9 = *(undefined1 **)(puVar9 + 0xc);
      }
    }
  }
  return pvVar10;
}

