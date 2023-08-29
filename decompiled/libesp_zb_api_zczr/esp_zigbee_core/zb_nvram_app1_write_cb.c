/*
 * Last changed at upstream commit 327f0a5451f37830bdf6e6c5c0e1933fae07fcf0
 * https://github.com/espressif/esp-zigbee-sdk/commit/327f0a5451f37830bdf6e6c5c0e1933fae07fcf0
 * Upstream date: 2023-08-29 15:32:50 +0800
 * Upstream subject: esp-zigbee-sdk: add support zigbee sleep
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
      uVar3 = (uint)(byte)(&DAT_0001467d)[iVar7 * 0xc];
      for (iVar6 = (&DAT_00014680)[iVar7 * 3]; uVar1 = uVar1 & 0xffff, iVar6 != 0;
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
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC6,uVar5,"ESP_ZIGBEE_CORE","zb_nvram_app1_write_cb",200
                     );
        return -1;
      }
    }
    iVar7 = iVar7 + 1;
  } while( true );
}

