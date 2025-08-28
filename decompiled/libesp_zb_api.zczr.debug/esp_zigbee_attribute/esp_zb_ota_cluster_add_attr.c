/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_ota_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ota_cluster_add_attr(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (param_2 == 8) {
    uVar7 = 1;
    uVar6 = 0x21;
    goto _L0;
  }
  if (param_2 < 9) {
    if (param_2 == 4) {
      uVar7 = 1;
      uVar6 = 0x23;
    }
    else if (param_2 < 5) {
      if (param_2 != 2) {
        if (param_2 < 3) {
          if (param_2 == 0) {
            uVar7 = 1;
            uVar6 = 0xf0;
          }
          else {
            if (param_2 != 1) goto _L0;
            uVar7 = 1;
            uVar6 = 0x23;
          }
          goto _L0;
        }
        if (param_2 == 3) {
          uVar7 = 1;
          uVar6 = 0x21;
          goto _L0;
        }
        goto _L0;
      }
      uVar7 = 1;
      uVar6 = 0x23;
    }
    else if (param_2 == 6) {
      uVar7 = 1;
      uVar6 = 0x30;
    }
    else if (param_2 == 7) {
      uVar7 = 1;
      uVar6 = 0x21;
    }
    else {
      if (param_2 != 5) goto _L0;
      uVar7 = 1;
      uVar6 = 0x21;
    }
  }
  else {
    puVar2 = param_3;
    if (param_2 != 0xfff0) {
      if (param_2 < 0xfff1) {
        if (param_2 == 0xb) {
          uVar7 = 1;
          uVar6 = 0x30;
        }
        else if (param_2 < 0xc) {
          if (param_2 == 9) {
            uVar7 = 1;
            uVar6 = 0x21;
          }
          else {
            if (param_2 != 10) goto _L0;
            uVar7 = 1;
            uVar6 = 0x23;
          }
        }
        else {
          if (param_2 != 0xc) goto _L0;
          uVar7 = 1;
          uVar6 = 0x30;
        }
        goto _L0;
      }
      if (param_2 == 0xfff2) {
        uVar7 = 1;
        uVar6 = 0x21;
        goto _L0;
      }
      if (param_2 == 0xfff3) {
        uVar7 = 1;
        uVar6 = 0x20;
        goto _L0;
      }
      if (param_2 != 0xfff1) goto _L0;
      if (param_3 != (undefined4 *)0x0) {
        puVar2 = (undefined4 *)malloc(0x10);
        *puVar2 = 0;
        uVar1 = *(undefined2 *)param_3;
        *(undefined2 *)(puVar2 + 1) = uVar1;
        *(undefined2 *)((int)puVar2 + 6) = uVar1;
        *(undefined2 *)(puVar2 + 2) = *(undefined2 *)((int)param_3 + 2);
        *(undefined1 *)((int)puVar2 + 10) = *(undefined1 *)(param_3 + 1);
        *(undefined1 *)((int)puVar2 + 0xb) = 0;
        *(undefined1 *)(puVar2 + 3) = 0;
        uVar7 = 0x40;
        uVar6 = 0x10;
        param_3 = puVar2;
        goto _L0;
      }
      zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c",
                0x61f);
    }
    if (puVar2 == (undefined4 *)0x0) {
      zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c",
                0x636);
_L0:
      uVar6 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC11,uVar6,0x10000);
      return 0x102;
    }
    puVar2 = (undefined4 *)malloc(0x10);
    pvVar3 = calloc((uint)*(byte *)(param_3 + 2),8);
    puVar4 = (undefined1 *)malloc(1);
    *puVar2 = puVar4;
    *puVar4 = *(undefined1 *)param_3;
    puVar5 = (undefined4 *)malloc(4);
    puVar2[1] = puVar5;
    *puVar5 = param_3[1];
    *(undefined1 *)(puVar2 + 2) = *(undefined1 *)(param_3 + 2);
    puVar2[3] = pvVar3;
    uVar7 = 0x40;
    uVar6 = 0x10;
    param_3 = puVar2;
  }
_L0:
  uVar6 = esp_zb_internal_cluster_add_attr(param_1,0x19,param_2,uVar6,uVar7,param_3,0xffff);
  return uVar6;
}

