/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> reset_endpoint_to_factory_default
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 reset_endpoint_to_factory_default(undefined1 *param_1,int param_2,code *param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  void *__src;
  void *__s;
  int iVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_90 [28];
  undefined2 uStack_74;
  ushort uStack_72;
  undefined2 uStack_70;
  undefined2 uStack_6e;
  void *pvStack_6c;
  undefined1 uStack_68;
  undefined1 uStack_67;
  undefined2 uStack_66;
  undefined1 uStack_64;
  undefined2 uStack_62;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_3c;
  undefined2 uStack_34;
  undefined2 uStack_32;
  
  if (param_1 == (undefined1 *)0x0) {
    return 0xffffffff;
  }
  iVar5 = 0;
  do {
    if ((int)(uint)(byte)param_1[0x10] <= iVar5) {
      return 0;
    }
    puVar1 = (undefined2 *)(*(int *)(param_1 + 0x11) + iVar5 * 0xf);
    if (puVar1 == (undefined2 *)0x0) {
      return 0xffffffff;
    }
    if (*(code **)((int)puVar1 + 0xb) != (code *)0x0) {
      (**(code **)((int)puVar1 + 0xb))();
    }
    for (iVar6 = 0; iVar6 < (int)(uint)(ushort)puVar1[1]; iVar6 = iVar6 + 1) {
      puVar2 = (undefined2 *)(*(int *)(puVar1 + 2) + iVar6 * 10);
      sVar4 = (size_t)*(byte *)(puVar2 + 1);
      if ((*(byte *)((int)puVar2 + 3) & 0x40) == 0) {
        sVar4 = esp_zb_zcl_get_attribute_size(*(undefined4 *)(puVar2 + 3));
      }
      uStack_74 = *puVar2;
      uStack_70 = 0;
      uStack_6e = (undefined2)sVar4;
      uStack_72 = (ushort)*(byte *)(puVar2 + 1);
      __s = *(void **)(puVar2 + 3);
      pvStack_6c = __s;
      if (param_3 == (code *)0x0) {
_L0:
        memset(__s,0,sVar4);
      }
      else {
        memcpy(auStack_90,&uStack_74,0xc);
        __src = (void *)(*param_3)(*param_1,*puVar1,auStack_90);
        __s = *(void **)(puVar2 + 3);
        if (__src == (void *)0x0) goto _L0;
        memcpy(*(void **)(puVar2 + 3),__src,sVar4);
      }
    }
    if ((*(int *)(puVar1 + 2) != 0) && (param_2 != 0)) {
      memset(&uStack_68,0,0x38);
      uStack_67 = *param_1;
      uStack_66 = *puVar1;
      uStack_64 = *(undefined1 *)(puVar1 + 4);
      uStack_34 = *(undefined2 *)(param_1 + 1);
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_3c = 5;
      for (iVar6 = 0; iVar6 < (int)(uint)(ushort)puVar1[1]; iVar6 = iVar6 + 1) {
        puVar2 = (undefined2 *)(*(int *)(puVar1 + 2) + iVar6 * 10);
        if ((*(byte *)((int)puVar2 + 3) & 4) != 0) {
          uStack_62 = *puVar2;
          uStack_32 = puVar2[2];
          iVar3 = zb_zcl_is_analog_data_type(*(undefined1 *)(puVar2 + 1));
          if (iVar3 != 0) {
            sVar4 = zb_zcl_get_analog_attribute_size(*(undefined1 *)(puVar2 + 1));
            memset(&uStack_4c,0,sVar4);
          }
          zb_zcl_put_reporting_info(&uStack_68,1);
        }
      }
    }
    iVar5 = iVar5 + 1;
  } while( true );
}

