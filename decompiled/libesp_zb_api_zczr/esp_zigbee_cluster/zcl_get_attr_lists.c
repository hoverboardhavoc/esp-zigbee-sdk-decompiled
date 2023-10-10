/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> zcl_get_attr_lists
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
  undefined1 uVar8;
  undefined1 uVar9;
  char cVar10;
  undefined1 *puVar11;
  void *pvVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined1 *puVar15;
  int iVar16;
  
  if (param_1 == 0) {
    uVar13 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC7,uVar13,"ESP_ZIGBEE_CLUSTER");
    pvVar12 = (void *)0x0;
  }
  else {
    cVar10 = '\0';
    iVar16 = param_1;
    while (iVar16 = *(int *)(iVar16 + 0xc), iVar16 != 0) {
      cVar10 = cVar10 + '\x01';
    }
    if (cVar10 == '\0') {
      uVar13 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_CLUSTER",&_LC8,uVar13,"ESP_ZIGBEE_CLUSTER");
      pvVar12 = (void *)0x0;
    }
    else {
      zcl_finish_attr_lists();
      puVar11 = *(undefined1 **)(param_1 + 0xc);
      pvVar12 = calloc((uint)(byte)(cVar10 + 1),10);
      for (uVar14 = 0; uVar14 < (byte)(cVar10 + 1); uVar14 = uVar14 + 1 & 0xff) {
        puVar15 = (undefined1 *)(uVar14 * 10 + (int)pvVar12);
        uVar1 = puVar11[1];
        uVar2 = puVar11[2];
        uVar3 = puVar11[3];
        uVar4 = puVar11[4];
        uVar5 = puVar11[5];
        uVar6 = puVar11[6];
        uVar7 = puVar11[7];
        uVar8 = puVar11[8];
        uVar9 = puVar11[9];
        *puVar15 = *puVar11;
        puVar15[1] = uVar1;
        puVar15[2] = uVar2;
        puVar15[3] = uVar3;
        puVar15[4] = uVar4;
        puVar15[5] = uVar5;
        puVar15[6] = uVar6;
        puVar15[7] = uVar7;
        puVar15[8] = uVar8;
        puVar15[9] = uVar9;
        puVar11 = *(undefined1 **)(puVar11 + 0xc);
      }
    }
  }
  return pvVar12;
}

