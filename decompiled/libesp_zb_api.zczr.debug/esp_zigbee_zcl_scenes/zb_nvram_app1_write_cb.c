/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zb_nvram_app1_write_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_nvram_app1_write_cb(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  size_t __size;
  short *__s;
  undefined4 uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  
  __size = zb_nvram_app1_data_size_cb();
  __s = (short *)malloc(__size);
  if (__s == (short *)0x0) {
    uVar9 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_LC20,uVar9,"ESP_ZIGBEE_ZCL_SCENES",
                  "zb_nvram_app1_write_cb",0xa8,__size);
    uVar9 = 0xffffffea;
  }
  else {
    memset(__s,0,__size);
    uVar13 = 2;
    for (iVar14 = 0; iVar14 < (int)(uint)esp_zb_zcl_scenes_table_capacity; iVar14 = iVar14 + 1) {
      puVar11 = (undefined1 *)(s_nvram_app1_data + iVar14 * 0xc);
      if ((puVar11 != (undefined1 *)0x0) && (*(short *)(puVar11 + 2) != -1)) {
        puVar10 = (undefined1 *)((int)__s + uVar13);
        uVar2 = puVar11[1];
        uVar3 = puVar11[2];
        uVar4 = puVar11[3];
        uVar5 = puVar11[4];
        uVar6 = puVar11[5];
        uVar7 = puVar11[6];
        uVar8 = puVar11[7];
        *puVar10 = *puVar11;
        puVar10[1] = uVar2;
        puVar10[2] = uVar3;
        puVar10[3] = uVar4;
        puVar10[4] = uVar5;
        puVar10[5] = uVar6;
        puVar10[6] = uVar7;
        puVar10[7] = uVar8;
        uVar13 = uVar13 + 8;
        uVar12 = (uint)(byte)puVar11[7];
        for (puVar11 = *(undefined1 **)(puVar11 + 8); uVar13 = uVar13 & 0xffff,
            puVar11 != (undefined1 *)0x0; puVar11 = *(undefined1 **)(puVar11 + 8)) {
          *(undefined1 *)((int)__s + uVar13) = *puVar11;
          ((undefined1 *)((int)__s + uVar13))[1] = puVar11[1];
          bVar1 = puVar11[2];
          *(byte *)((uVar13 + 2 & 0xffff) + (int)__s) = bVar1;
          uVar13 = uVar13 + 3 & 0xffff;
          memcpy((void *)((int)__s + uVar13),*(void **)(puVar11 + 4),(uint)bVar1);
          uVar13 = (byte)puVar11[2] + uVar13;
          uVar12 = (uVar12 - 3 & 0xffff) - (uint)(byte)puVar11[2] & 0xffff;
        }
        if (uVar12 != 0) {
          uVar9 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_LC21,uVar9,"ESP_ZIGBEE_ZCL_SCENES",
                        "zb_nvram_app1_write_cb",0xbe);
          uVar9 = 0xffffffff;
          goto _L0;
        }
      }
    }
    *__s = (short)uVar13 + -2;
    uVar9 = zb_nvram_write_data(param_1,param_2,__s,__size);
_L0:
    free(__s);
  }
  return uVar9;
}

