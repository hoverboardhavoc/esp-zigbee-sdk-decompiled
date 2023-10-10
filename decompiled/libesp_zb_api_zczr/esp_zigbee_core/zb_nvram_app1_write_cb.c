/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_nvram_app1_write_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_nvram_app1_write_cb(undefined4 param_1,int param_2)

{
  uint uVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  uVar1 = 0;
  iVar4 = 0;
  do {
    if (9 < iVar7) {
      return iVar4;
    }
    psVar2 = &esp_zb_zcl_scenes_table + iVar7 * 6;
    if ((psVar2 != (short *)0x0) && (*psVar2 != -1)) {
      iVar4 = zb_nvram_write_data(param_1,uVar1 + param_2,psVar2,6);
      uVar1 = uVar1 + 6;
      uVar3 = (uint)(byte)(&DAT_00015a55)[iVar7 * 0xc];
      for (iVar6 = (&DAT_00015a58)[iVar7 * 3]; uVar1 = uVar1 & 0xffff, iVar6 != 0;
          iVar6 = *(int *)(iVar6 + 8)) {
        zb_nvram_write_data(param_1,uVar1 + param_2,iVar6,2);
        zb_nvram_write_data(param_1,(uVar1 + 2 & 0xffff) + param_2,iVar6 + 2,1);
        uVar1 = uVar1 + 3 & 0xffff;
        iVar4 = zb_nvram_write_data(param_1,uVar1 + param_2,*(undefined4 *)(iVar6 + 4),
                                    *(undefined1 *)(iVar6 + 2));
        uVar1 = uVar1 + *(byte *)(iVar6 + 2);
        uVar3 = (uVar3 - 3 & 0xffff) - (uint)*(byte *)(iVar6 + 2) & 0xffff;
      }
      if ((uVar3 != 0) || (iVar4 != 0)) {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC57,uVar5,"ESP_ZIGBEE_CORE","zb_nvram_app1_write_cb",
                      0xca);
        return -1;
      }
    }
    iVar7 = iVar7 + 1;
  } while( true );
}

