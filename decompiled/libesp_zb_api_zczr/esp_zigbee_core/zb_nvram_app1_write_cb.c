/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
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
    if ((&esp_zb_zcl_scenes_table + iVar10 != (byte *)0x0) &&
       (*(short *)(&DAT_000176fa + iVar10) != -1)) {
      pbVar13 = abStack_40 + uVar12 + iVar8;
      bVar1 = (&DAT_000176f9)[iVar10];
      bVar2 = (&DAT_000176fa)[iVar10];
      bVar3 = (&DAT_000176fb)[iVar10];
      bVar4 = (&DAT_000176fc)[iVar10];
      bVar5 = (&DAT_000176fd)[iVar10];
      bVar6 = (&DAT_000176fe)[iVar10];
      bVar7 = (&DAT_000176ff)[iVar10];
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
      for (pbVar13 = (byte *)(&DAT_00017700)[iVar14 * 3]; uVar12 = uVar12 & 0xffff,
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
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC44,uVar9,"ESP_ZIGBEE_CORE","zb_nvram_app1_write_cb",
                      0xf8);
        return 0xffffffff;
      }
    }
    iVar14 = iVar14 + 1;
  } while( true );
}

