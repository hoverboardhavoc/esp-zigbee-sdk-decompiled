/*
 * Last changed at upstream commit a67793c7af0a02d983345915fecc5d8fce7a0945
 * https://github.com/espressif/esp-zigbee-sdk/commit/a67793c7af0a02d983345915fecc5d8fce7a0945
 * Upstream date: 2024-02-22 20:57:09 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.2(af7a8c4d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_nvram_app1_write_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_nvram_app1_write_cb(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  size_t __n;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  byte abStack_40 [14];
  undefined2 local_32;
  
  __n = zb_nvram_app1_data_size_cb();
  local_32 = 0;
  iVar8 = -(__n + 0xf & 0xfffffff0);
  memset(abStack_40 + iVar8,0,__n);
  iVar14 = 0;
  uVar12 = 2;
  do {
    if (0xf < iVar14) {
      local_32 = (short)uVar12 + -2;
      abStack_40[iVar8] = (undefined1)local_32;
      abStack_40[iVar8 + 1] = local_32._1_1_;
      uVar9 = zb_nvram_write_data(param_1,param_2,abStack_40 + iVar8,__n);
      return uVar9;
    }
    iVar10 = iVar14 * 0xc;
    if ((&esp_zb_zcl_scenes_table + iVar10 != (byte *)0x0) && ((&DAT_00018e5e)[iVar14 * 6] != -1)) {
      pbVar13 = abStack_40 + uVar12 + iVar8;
      bVar1 = (&DAT_00018e5d)[iVar10];
      bVar2 = *(byte *)(&DAT_00018e5e + iVar14 * 6);
      bVar3 = *(byte *)((int)&DAT_00018e5e + iVar10 + 1);
      bVar4 = *(byte *)(&DAT_00018e60 + iVar14 * 6);
      bVar5 = *(byte *)((int)&DAT_00018e60 + iVar10 + 1);
      bVar6 = (&DAT_00018e62)[iVar10];
      bVar7 = (&DAT_00018e63)[iVar10];
      uVar11 = (uint)bVar7;
      *pbVar13 = (&esp_zb_zcl_scenes_table)[iVar10];
      pbVar13[1] = bVar1;
      pbVar13[2] = bVar2;
      pbVar13[3] = bVar3;
      pbVar13[4] = bVar4;
      pbVar13[5] = bVar5;
      pbVar13[6] = bVar6;
      pbVar13[7] = bVar7;
      uVar12 = uVar12 + 8;
      for (pbVar13 = (byte *)(&DAT_00018e64)[iVar14 * 3]; uVar12 = uVar12 & 0xffff,
          pbVar13 != (byte *)0x0; pbVar13 = *(byte **)(pbVar13 + 8)) {
        abStack_40[uVar12 + iVar8] = *pbVar13;
        (abStack_40 + uVar12 + iVar8)[1] = pbVar13[1];
        bVar1 = pbVar13[2];
        abStack_40[(uVar12 + 2 & 0xffff) + iVar8] = bVar1;
        uVar12 = uVar12 + 3 & 0xffff;
        memcpy(abStack_40 + uVar12 + iVar8,*(void **)(pbVar13 + 4),(uint)bVar1);
        uVar12 = pbVar13[2] + uVar12;
        uVar11 = (uVar11 - 3 & 0xffff) - (uint)pbVar13[2] & 0xffff;
      }
      if (uVar11 != 0) {
        uVar9 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar9,"ESP_ZIGBEE_CORE","zb_nvram_app1_write_cb",0xea
                     );
        return 0xffffffff;
      }
    }
    iVar14 = iVar14 + 1;
  } while( true );
}

