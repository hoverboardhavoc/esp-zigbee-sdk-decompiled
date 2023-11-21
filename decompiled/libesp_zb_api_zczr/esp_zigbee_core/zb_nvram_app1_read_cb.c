/*
 * Last changed at upstream commit 6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * https://github.com/espressif/esp-zigbee-sdk/commit/6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * Upstream date: 2023-11-21 18:28:11 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.4(be3a8a97)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_nvram_app1_read_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_nvram_app1_read_cb(uint param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  byte *pbVar10;
  void *__dest;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  byte abStack_40 [12];
  
  iVar6 = -(param_1 + 0x10 & 0xfffffff0);
  if (param_1 < 6) {
    uVar9 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC42,uVar9,"ESP_ZIGBEE_CORE","zb_nvram_app1_read_cb",0x8d);
  }
  else {
    iVar8 = zb_nvram_read_data(abStack_40 + iVar6,param_1);
    uVar7 = 0;
    uVar12 = 0;
    while ((uVar7 + 6 <= param_1 && (uVar12 < 10))) {
      if (iVar8 == 0) {
        pbVar13 = abStack_40 + uVar7 + iVar6;
        iVar14 = uVar12 * 0xc;
        bVar1 = pbVar13[1];
        bVar2 = pbVar13[2];
        bVar3 = pbVar13[3];
        bVar4 = pbVar13[4];
        bVar5 = pbVar13[5];
        *(byte *)(&esp_zb_zcl_scenes_table + uVar12 * 6) = *pbVar13;
        *(byte *)((int)&esp_zb_zcl_scenes_table + iVar14 + 1) = bVar1;
        *(byte *)(&DAT_00016f36 + uVar12 * 6) = bVar2;
        *(byte *)((int)&DAT_00016f36 + iVar14 + 1) = bVar3;
        (&DAT_00016f38)[iVar14] = bVar4;
        (&DAT_00016f39)[iVar14] = bVar5;
        uVar7 = uVar7 + 6;
        uVar11 = (uint)pbVar13[5];
        pbVar13 = (byte *)0x0;
        while (uVar7 = uVar7 & 0xffff, uVar11 != 0) {
          pbVar10 = (byte *)malloc(0xc);
          *pbVar10 = abStack_40[uVar7 + iVar6];
          pbVar10[1] = (abStack_40 + uVar7 + iVar6)[1];
          bVar1 = abStack_40[(uVar7 + 2 & 0xffff) + iVar6];
          pbVar10[2] = bVar1;
          uVar7 = uVar7 + 3 & 0xffff;
          __dest = malloc((uint)bVar1);
          *(void **)(pbVar10 + 4) = __dest;
          memcpy(__dest,abStack_40 + uVar7 + iVar6,(uint)bVar1);
          uVar7 = uVar7 + pbVar10[2];
          uVar11 = (uVar11 - 3 & 0xffff) - (uint)pbVar10[2] & 0xffff;
          pbVar10[8] = 0;
          pbVar10[9] = 0;
          pbVar10[10] = 0;
          pbVar10[0xb] = 0;
          if (pbVar13 == (byte *)0x0) {
            (&DAT_00016f3c)[uVar12 * 3] = pbVar10;
            pbVar13 = pbVar10;
          }
          else {
            *(byte **)(pbVar13 + 8) = pbVar10;
            pbVar13 = pbVar10;
          }
        }
        uVar12 = uVar12 + 1 & 0xff;
      }
    }
  }
  return;
}

