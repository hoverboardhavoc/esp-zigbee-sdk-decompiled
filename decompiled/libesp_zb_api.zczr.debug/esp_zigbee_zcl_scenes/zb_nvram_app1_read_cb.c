/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zb_nvram_app1_read_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_nvram_app1_read_cb(uint param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  byte bVar8;
  ushort uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined1 *puVar14;
  void *__dest;
  undefined1 *puVar15;
  uint uVar16;
  uint uVar17;
  undefined1 *puVar18;
  int iVar19;
  undefined2 uStack_40;
  byte abStack_3e [10];
  
  iVar11 = -(param_1 + 0x10 & 0xfffffff0);
  if (param_1 < 2) {
    uVar13 = esp_log_timestamp(param_1);
    esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_LC22,uVar13,"ESP_ZIGBEE_ZCL_SCENES",
                  "zb_nvram_app1_read_cb",0x52);
  }
  else {
    iVar12 = zb_nvram_read_data((int)&uStack_40 + iVar11);
    uVar9 = *(ushort *)((int)&uStack_40 + iVar11);
    uVar10 = 2;
    uVar17 = 0;
    while (uVar10 + 8 <= (uVar9 + 2 & 0xffff)) {
      if (0xf < uVar17) {
        iVar11 = 0;
        goto _L0;
      }
      if (iVar12 == 0) {
        puVar18 = (undefined1 *)((int)&uStack_40 + uVar10 + iVar11);
        iVar19 = uVar17 * 0xc;
        uVar1 = puVar18[1];
        uVar2 = puVar18[2];
        uVar3 = puVar18[3];
        uVar4 = puVar18[4];
        uVar5 = puVar18[5];
        uVar6 = puVar18[6];
        uVar7 = puVar18[7];
        (&esp_zb_zcl_scenes_table)[iVar19] = *puVar18;
        (&DAT_00012c7d)[iVar19] = uVar1;
        *(undefined1 *)(&DAT_00012c7e + uVar17 * 6) = uVar2;
        *(undefined1 *)((int)&DAT_00012c7e + iVar19 + 1) = uVar3;
        (&DAT_00012c80)[iVar19] = uVar4;
        (&DAT_00012c81)[iVar19] = uVar5;
        (&DAT_00012c82)[iVar19] = uVar6;
        (&DAT_00012c83)[iVar19] = uVar7;
        uVar10 = uVar10 + 8;
        uVar16 = (uint)(byte)puVar18[7];
        puVar18 = (undefined1 *)0x0;
        while (uVar10 = uVar10 & 0xffff, uVar16 != 0) {
          puVar14 = (undefined1 *)malloc(0xc);
          puVar15 = (undefined1 *)((int)&uStack_40 + uVar10 + iVar11);
          *puVar14 = *puVar15;
          puVar14[1] = puVar15[1];
          bVar8 = *(byte *)((int)&uStack_40 + (uVar10 + 2 & 0xffff) + iVar11);
          puVar14[2] = bVar8;
          uVar10 = uVar10 + 3 & 0xffff;
          __dest = malloc((uint)bVar8);
          *(void **)(puVar14 + 4) = __dest;
          memcpy(__dest,(void *)((int)&uStack_40 + uVar10 + iVar11),(uint)bVar8);
          uVar10 = uVar10 + (byte)puVar14[2];
          uVar16 = (uVar16 - 3 & 0xffff) - (uint)(byte)puVar14[2] & 0xffff;
          *(undefined4 *)(puVar14 + 8) = 0;
          if (puVar18 == (undefined1 *)0x0) {
            (&DAT_00012c84)[uVar17 * 3] = puVar14;
            puVar18 = puVar14;
          }
          else {
            *(undefined1 **)(puVar18 + 8) = puVar14;
            puVar18 = puVar14;
          }
        }
        uVar17 = uVar17 + 1 & 0xff;
      }
    }
    iVar11 = 0;
_L0:
    for (; iVar11 < 0x10; iVar11 = iVar11 + 1) {
      if ((&DAT_00012c7e)[iVar11 * 6] != -1) {
        zb_zcl_scenes_set_scene_count((&esp_zb_zcl_scenes_table)[iVar11 * 0xc],1);
      }
    }
  }
  return;
}

