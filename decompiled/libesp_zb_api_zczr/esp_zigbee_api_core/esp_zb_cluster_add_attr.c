/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> esp_zb_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_add_attr(int param_1,uint param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort *puVar2;
  undefined2 *__ptr;
  undefined4 uVar3;
  ushort *puVar4;
  
  __ptr = (undefined2 *)malloc(0x10);
  if (param_1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_L0,uVar3,"ESP_ZIGBEE_API_CORE");
    return 0x102;
  }
  uVar1 = (*(ushort **)(param_1 + 0xc))[4];
  puVar2 = *(ushort **)(param_1 + 0xc);
  do {
    puVar4 = puVar2;
    if (puVar4 == (ushort *)0x0) break;
    if (*puVar4 == param_2) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_L0,uVar3,"ESP_ZIGBEE_API_CORE",param_2);
      return 0x102;
    }
    puVar2 = *(ushort **)(puVar4 + 6);
  } while (*(ushort **)(puVar4 + 6) != (ushort *)0x0);
  *__ptr = (short)param_2;
  if (uVar1 == 5) {
    if (param_2 == 2) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
    }
    else if (param_2 < 3) {
      if (param_2 == 0) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
      }
      else {
        if (param_2 != 1) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
      }
    }
    else if (param_2 == 3) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x10;
    }
    else {
      if (param_2 != 4) {
_L0:
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_LC9,uVar3,"ESP_ZIGBEE_API_CORE");
        free(__ptr);
        return 0x102;
      }
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x18;
    }
  }
  else if (uVar1 < 6) {
    if (uVar1 == 3) {
      if (param_2 != 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_LC9,uVar3,"ESP_ZIGBEE_API_CORE");
        free(__ptr);
        return 0x102;
      }
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x21;
    }
    else if (uVar1 == 4) {
      if (param_2 != 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_LC9,uVar3,"ESP_ZIGBEE_API_CORE");
        free(__ptr);
        return 0x102;
      }
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x18;
    }
    else {
      if (uVar1 != 0) {
_L0:
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_LC10,uVar3,"ESP_ZIGBEE_API_CORE");
        free(__ptr);
        return 0x102;
      }
      if (param_2 == 1) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
      }
      else if (param_2 == 7) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x30;
      }
      else {
        if (param_2 != 0) {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_LC9,uVar3,"ESP_ZIGBEE_API_CORE");
          free(__ptr);
          return 0x102;
        }
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
      }
    }
  }
  else if (uVar1 == 8) {
    if (param_2 == 0) {
      *(undefined1 *)((int)__ptr + 3) = 0x15;
      *(undefined1 *)(__ptr + 1) = 0x20;
    }
    else {
      if (param_2 != 0xefff) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_LC9,uVar3,"ESP_ZIGBEE_API_CORE");
        free(__ptr);
        return 0x102;
      }
      *(undefined1 *)((int)__ptr + 3) = 0x40;
      *(undefined1 *)(__ptr + 1) = 0;
    }
  }
  else if (uVar1 == 0x300) {
    if (param_2 == 0x4001) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x30;
    }
    else if (param_2 < 0x4002) {
      if (param_2 == 7) {
        *(undefined1 *)((int)__ptr + 3) = 0x15;
        *(undefined1 *)(__ptr + 1) = 0x21;
      }
      else if (param_2 < 8) {
        if (param_2 == 3) {
          *(undefined1 *)((int)__ptr + 3) = 0x15;
          *(undefined1 *)(__ptr + 1) = 0x21;
        }
        else if (param_2 < 4) {
          if (param_2 == 0) {
            *(undefined1 *)((int)__ptr + 3) = 5;
            *(undefined1 *)(__ptr + 1) = 0x20;
          }
          else {
            if (param_2 != 1) goto _L0;
            *(undefined1 *)((int)__ptr + 3) = 0x15;
            *(undefined1 *)(__ptr + 1) = 0x20;
          }
        }
        else {
          if (param_2 != 4) {
_L0:
            uVar3 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_LC9,uVar3,"ESP_ZIGBEE_API_CORE");
            free(__ptr);
            return 0x102;
          }
          *(undefined1 *)((int)__ptr + 3) = 0x15;
          *(undefined1 *)(__ptr + 1) = 0x21;
        }
      }
      else if (param_2 == 0xf) {
        *(undefined1 *)((int)__ptr + 3) = 3;
        *(undefined1 *)(__ptr + 1) = 0x18;
      }
      else if (param_2 == 0x4000) {
        *(undefined1 *)((int)__ptr + 3) = 0x11;
        *(undefined1 *)(__ptr + 1) = 0x21;
      }
      else {
        if (param_2 != 8) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x30;
      }
    }
    else if (param_2 == 0x4006) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
    }
    else if (param_2 < 0x4007) {
      if (param_2 == 0x4004) {
        *(undefined1 *)((int)__ptr + 3) = 0x11;
        *(undefined1 *)(__ptr + 1) = 0x21;
      }
      else if (param_2 < 0x4005) {
        if (param_2 == 0x4002) {
          *(undefined1 *)((int)__ptr + 3) = 0x11;
          *(undefined1 *)(__ptr + 1) = 0x20;
        }
        else {
          if (param_2 != 0x4003) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 0x11;
          *(undefined1 *)(__ptr + 1) = 0x20;
        }
      }
      else {
        if (param_2 != 0x4005) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x21;
      }
    }
    else if (param_2 == 0x400b) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
    }
    else if (param_2 == 0x400c) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
    }
    else {
      if (param_2 != 0x400a) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x19;
    }
  }
  else {
    if (uVar1 != 6) goto _L0;
    if (param_2 != 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_LC9,uVar3,"ESP_ZIGBEE_API_CORE");
      free(__ptr);
      return 0x102;
    }
    *(undefined1 *)((int)__ptr + 3) = 0x15;
    *(undefined1 *)(__ptr + 1) = 0x10;
  }
  *(undefined4 *)(__ptr + 2) = param_3;
  __ptr[4] = uVar1;
  *(undefined4 *)(__ptr + 6) = 0;
  if (puVar4 == (ushort *)0x0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(puVar4 + 6) = __ptr;
  }
  return 0;
}

