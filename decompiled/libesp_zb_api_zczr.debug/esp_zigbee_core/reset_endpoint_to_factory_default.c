/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> reset_endpoint_to_factory_default
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
  void *__src;
  int iVar5;
  int iVar6;
  int iVar7;
  size_t sVar8;
  uint local_90;
  int iStack_8c;
  void *pvStack_88;
  uint uStack_74;
  int iStack_70;
  void *pvStack_6c;
  int iStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
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
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC1,uVar4,"ESP_ZIGBEE_CORE",
                  "reset_endpoint_to_factory_default",0x3a4);
    uVar4 = 0xffffffff;
  }
  else {
    for (iVar7 = 0; iVar7 < (int)(uint)(byte)param_1[0x10]; iVar7 = iVar7 + 1) {
      puVar3 = (undefined2 *)(*(int *)(param_1 + 0x11) + iVar7 * 0xf);
      if (puVar3 == (undefined2 *)0x0) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC2,uVar4,"ESP_ZIGBEE_CORE",
                      "reset_endpoint_to_factory_default",0x3a7);
        return 0xffffffff;
      }
      if (*(code **)((int)puVar3 + 0xb) != (code *)0x0) {
        (**(code **)((int)puVar3 + 0xb))();
      }
      for (iVar6 = 0; iVar6 < (int)(uint)(ushort)puVar3[1]; iVar6 = iVar6 + 1) {
        puVar1 = (uint3 *)(*(int *)(puVar3 + 2) + iVar6 * 10);
        if ((*(byte *)((int)puVar1 + 3) & 0x40) == 0) {
          sVar8 = esp_zb_zcl_get_attribute_size
                            (*(undefined1 *)((int)puVar1 + 2),*(undefined4 *)((int)puVar1 + 6));
        }
        else {
          sVar8 = (size_t)*(byte *)((int)puVar1 + 2);
        }
        uStack_74 = (uint)*puVar1;
        iStack_70 = sVar8 << 0x10;
        pvStack_6c = *(void **)((int)puVar1 + 6);
        if (param_3 == (code *)0x0) {
          memset(pvStack_6c,0,sVar8);
        }
        else {
          local_90 = uStack_74;
          iStack_8c = iStack_70;
          pvStack_88 = pvStack_6c;
          __src = (void *)(*param_3)(*param_1,*puVar3,&local_90);
          if (__src == (void *)0x0) {
            memset(*(void **)((int)puVar1 + 6),0,sVar8);
          }
          else {
            memcpy(*(void **)((int)puVar1 + 6),__src,sVar8);
          }
        }
      }
      if ((*(int *)(puVar3 + 2) != 0) && (param_2 != 0)) {
        uStack_60 = 0;
        uStack_5c = 0;
        uStack_58 = 0;
        uStack_54 = 0;
        uStack_50 = 0;
        uStack_4c = 0;
        uStack_48 = 0;
        uStack_44 = 0;
        uStack_40 = 0;
        uStack_38 = 0;
        iStack_68 = (uint)CONCAT21(*puVar3,*param_1) << 8;
        uStack_64 = (uint)*(byte *)(puVar3 + 4);
        uStack_34 = (uint)*(ushort *)(param_1 + 1);
        uStack_3c = 5;
        for (iVar6 = 0; iVar6 < (int)(uint)(ushort)puVar3[1]; iVar6 = iVar6 + 1) {
          puVar2 = (undefined2 *)(*(int *)(puVar3 + 2) + iVar6 * 10);
          if ((*(byte *)((int)puVar2 + 3) & 4) != 0) {
            uStack_64 = CONCAT22(*puVar2,(undefined2)uStack_64);
            uStack_34 = CONCAT22(puVar2[2],(undefined2)uStack_34);
            iVar5 = zb_zcl_is_analog_data_type(*(undefined1 *)(puVar2 + 1));
            if (iVar5 != 0) {
              sVar8 = zb_zcl_get_analog_attribute_size(*(undefined1 *)(puVar2 + 1));
              memset(&uStack_4c,0,sVar8);
            }
            zb_zcl_put_reporting_info(&iStack_68,1);
          }
        }
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}

