/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_ota_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ota_cluster_add_attr(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_2 == 8) {
    uVar4 = 1;
    uVar3 = 0x21;
    goto _L0;
  }
  if (param_2 < 9) {
    if (param_2 == 4) {
      uVar4 = 1;
      uVar3 = 0x23;
    }
    else if (param_2 < 5) {
      if (param_2 != 2) {
        if (param_2 < 3) {
          if (param_2 == 0) {
            uVar4 = 1;
            uVar3 = 0xf0;
          }
          else {
            if (param_2 != 1) goto _L0;
            uVar4 = 1;
            uVar3 = 0x23;
          }
          goto _L0;
        }
        if (param_2 == 3) {
          uVar4 = 1;
          uVar3 = 0x21;
          goto _L0;
        }
        goto _L0;
      }
      uVar4 = 1;
      uVar3 = 0x23;
    }
    else if (param_2 == 6) {
      uVar4 = 1;
      uVar3 = 0x30;
    }
    else if (param_2 == 7) {
      uVar4 = 1;
      uVar3 = 0x21;
    }
    else {
      if (param_2 != 5) goto _L0;
      uVar4 = 1;
      uVar3 = 0x21;
    }
  }
  else {
    puVar1 = param_3;
    if (param_2 != 0xfff0) {
      if (param_2 < 0xfff1) {
        if (param_2 == 0xb) {
          uVar4 = 1;
          uVar3 = 0x30;
        }
        else if (param_2 < 0xc) {
          if (param_2 == 9) {
            uVar4 = 1;
            uVar3 = 0x21;
          }
          else {
            if (param_2 != 10) goto _L0;
            uVar4 = 1;
            uVar3 = 0x23;
          }
        }
        else {
          if (param_2 != 0xc) goto _L0;
          uVar4 = 1;
          uVar3 = 0x30;
        }
        goto _L0;
      }
      if (param_2 == 0xfff2) {
        uVar4 = 1;
        uVar3 = 0x21;
        goto _L0;
      }
      if (param_2 == 0xfff3) {
        uVar4 = 1;
        uVar3 = 0x20;
        goto _L0;
      }
      if (param_2 != 0xfff1) goto _L0;
      if (param_3 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)malloc(0x10);
        *puVar1 = 0;
        *(undefined2 *)(puVar1 + 1) = *(undefined2 *)param_3;
        *(undefined2 *)((int)puVar1 + 6) = 1;
        *(undefined2 *)(puVar1 + 2) = *(undefined2 *)((int)param_3 + 2);
        *(undefined1 *)((int)puVar1 + 10) = *(undefined1 *)(param_3 + 1);
        *(undefined1 *)((int)puVar1 + 0xb) = 0;
        *(undefined1 *)(puVar1 + 3) = 0;
        uVar4 = 0x40;
        uVar3 = 0x10;
        param_3 = puVar1;
        goto _L0;
      }
      zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c",
                0x616);
    }
    if (puVar1 == (undefined4 *)0x0) {
      zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c",
                0x62d);
_L0:
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC11,uVar3,0x10000);
      return 0x102;
    }
    puVar1 = (undefined4 *)malloc(0x10);
    pvVar2 = malloc((uint)*(byte *)(param_3 + 2) << 3);
    *puVar1 = param_3;
    puVar1[1] = param_3 + 1;
    *(undefined1 *)(puVar1 + 2) = *(undefined1 *)(param_3 + 2);
    puVar1[3] = pvVar2;
    uVar4 = 0x40;
    uVar3 = 0x10;
    param_3 = puVar1;
  }
_L0:
  uVar3 = esp_zb_internal_cluster_add_attr(param_1,0x19,param_2,uVar3,uVar4,param_3,0xffff);
  return uVar3;
}

