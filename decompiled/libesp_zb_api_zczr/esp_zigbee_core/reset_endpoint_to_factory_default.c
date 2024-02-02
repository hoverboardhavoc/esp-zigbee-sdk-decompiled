/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> reset_endpoint_to_factory_default
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 reset_endpoint_to_factory_default(undefined1 *param_1,int param_2,code *param_3)

{
  uint3 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  size_t sVar5;
  void *__src;
  int iVar6;
  int iVar7;
  int iVar8;
  uint local_80;
  int iStack_7c;
  void *pvStack_78;
  uint uStack_6c;
  int iStack_68;
  void *pvStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC44,uVar4,"ESP_ZIGBEE_CORE",
                  "reset_endpoint_to_factory_default",0xa4d);
    uVar4 = 0xffffffff;
  }
  else {
    for (iVar8 = 0; iVar8 < (int)(uint)(byte)param_1[0x10]; iVar8 = iVar8 + 1) {
      puVar3 = (undefined2 *)(*(int *)(param_1 + 0x11) + iVar8 * 0xf);
      if (puVar3 == (undefined2 *)0x0) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC45,uVar4,"ESP_ZIGBEE_CORE",
                      "reset_endpoint_to_factory_default",0xa50);
        return 0xffffffff;
      }
      if (*(code **)((int)puVar3 + 0xb) != (code *)0x0) {
        (**(code **)((int)puVar3 + 0xb))();
      }
      for (iVar7 = 0; iVar7 < (int)(uint)(ushort)puVar3[1]; iVar7 = iVar7 + 1) {
        puVar1 = (uint3 *)(*(int *)(puVar3 + 2) + iVar7 * 10);
        sVar5 = esp_zb_zcl_get_attribute_size
                          (*(undefined1 *)((int)puVar1 + 2),*(undefined4 *)((int)puVar1 + 6));
        uStack_6c = (uint)*puVar1;
        iStack_68 = sVar5 << 0x10;
        pvStack_64 = *(void **)((int)puVar1 + 6);
        if (param_3 == (code *)0x0) {
          memset(pvStack_64,0,sVar5);
        }
        else {
          local_80 = uStack_6c;
          iStack_7c = iStack_68;
          pvStack_78 = pvStack_64;
          __src = (void *)(*param_3)(*param_1,*puVar3,&local_80);
          if (__src == (void *)0x0) {
            memset(*(void **)((int)puVar1 + 6),0,sVar5);
          }
          else {
            memcpy(*(void **)((int)puVar1 + 6),__src,sVar5);
          }
        }
      }
      if ((*(int *)(puVar3 + 2) != 0) && (param_2 != 0)) {
        uStack_58 = 0;
        uStack_54 = 0;
        uStack_50 = 0;
        uStack_4c = 0;
        uStack_48 = 0;
        uStack_44 = 0;
        uStack_40 = 0;
        uStack_38 = 0;
        iStack_60 = (uint)CONCAT21(*puVar3,*param_1) << 8;
        uStack_5c = (uint)*(byte *)(puVar3 + 4);
        uStack_34 = (uint)*(ushort *)(param_1 + 1);
        uStack_3c = 5;
        for (iVar7 = 0; iVar7 < (int)(uint)(ushort)puVar3[1]; iVar7 = iVar7 + 1) {
          puVar2 = (undefined2 *)(*(int *)(puVar3 + 2) + iVar7 * 10);
          if ((*(byte *)((int)puVar2 + 3) & 4) != 0) {
            uStack_5c = CONCAT22(*puVar2,(undefined2)uStack_5c);
            uStack_34 = CONCAT22(puVar2[2],(undefined2)uStack_34);
            iVar6 = zb_zcl_is_analog_data_type(*(undefined1 *)(puVar2 + 1));
            if (iVar6 != 0) {
              sVar5 = zb_zcl_get_analog_attribute_size(*(undefined1 *)(puVar2 + 1));
              memset(&uStack_4c,0,sVar5);
            }
            zb_zcl_put_reporting_info(&iStack_60,1);
          }
        }
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}

