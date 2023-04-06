/*
 * Last changed at upstream commit 6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * https://github.com/espressif/esp-zigbee-sdk/commit/6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * Upstream date: 2023-04-06 16:02:34 +0800
 * Upstream subject: example: support single C6 gateway example and other API support(a1884f9)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_door_lock_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_door_lock_cluster_add_attr(int param_1,uint param_2,undefined4 param_3)

{
  undefined2 *__ptr;
  int iVar1;
  undefined4 uVar2;
  int aiStack_24 [4];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar1 = esp_zb_attr_list_get_tail(param_1,0x101,param_2,aiStack_24);
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return aiStack_24[0];
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x23) {
    *(undefined1 *)((int)__ptr + 3) = 7;
    *(undefined1 *)(__ptr + 1) = 0x23;
  }
  else if (param_2 < 0x24) {
    if (param_2 == 0x13) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
    }
    else if (param_2 < 0x14) {
      if (param_2 == 5) {
        *(undefined1 *)((int)__ptr + 3) = 3;
        *(undefined1 *)(__ptr + 1) = 0x23;
      }
      else if (param_2 < 6) {
        if (param_2 == 2) {
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x10;
        }
        else if (param_2 < 3) {
          if (param_2 == 0) {
            *(undefined1 *)((int)__ptr + 3) = 5;
            *(undefined1 *)(__ptr + 1) = 0x30;
          }
          else {
            if (param_2 != 1) goto _L0;
            *(undefined1 *)((int)__ptr + 3) = 1;
            *(undefined1 *)(__ptr + 1) = 0x30;
          }
        }
        else if (param_2 == 3) {
          *(undefined1 *)((int)__ptr + 3) = 5;
          *(undefined1 *)(__ptr + 1) = 0x30;
        }
        else {
          if (param_2 != 4) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 3;
          *(undefined1 *)(__ptr + 1) = 0x23;
        }
      }
      else if (param_2 == 0x11) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x21;
      }
      else if (param_2 < 0x12) {
        if (param_2 == 6) {
          *(undefined1 *)((int)__ptr + 3) = 3;
          *(undefined1 *)(__ptr + 1) = 0x21;
        }
        else {
          if (param_2 != 0x10) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x21;
        }
      }
      else {
        if (param_2 != 0x12) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x21;
      }
    }
    else if (param_2 == 0x19) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x20;
    }
    else if (param_2 < 0x1a) {
      if (param_2 == 0x16) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
      }
      else if (param_2 < 0x17) {
        if (param_2 == 0x14) {
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x20;
        }
        else {
          if (param_2 != 0x15) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x20;
        }
      }
      else if (param_2 == 0x17) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
      }
      else {
        if (param_2 != 0x18) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
      }
    }
    else if (param_2 == 0x21) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x42;
    }
    else if (param_2 < 0x22) {
      if (param_2 == 0x1a) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
      }
      else {
        if (param_2 != 0x20) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 7;
        *(undefined1 *)(__ptr + 1) = 0x10;
      }
    }
    else {
      if (param_2 != 0x22) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x20;
    }
  }
  else if (param_2 == 0x32) {
    *(undefined1 *)((int)__ptr + 3) = 7;
    *(undefined1 *)(__ptr + 1) = 0x10;
  }
  else if (param_2 < 0x33) {
    if (param_2 == 0x29) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x10;
    }
    else if (param_2 < 0x2a) {
      if (param_2 == 0x26) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x19;
      }
      else if (param_2 < 0x27) {
        if (param_2 == 0x24) {
          *(undefined1 *)((int)__ptr + 3) = 7;
          *(undefined1 *)(__ptr + 1) = 0x20;
        }
        else {
          if (param_2 != 0x25) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 7;
          *(undefined1 *)(__ptr + 1) = 0x30;
        }
      }
      else if (param_2 == 0x27) {
        *(undefined1 *)((int)__ptr + 3) = 5;
        *(undefined1 *)(__ptr + 1) = 0x19;
      }
      else {
        if (param_2 != 0x28) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 7;
        *(undefined1 *)(__ptr + 1) = 0x10;
      }
    }
    else if (param_2 == 0x30) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x20;
    }
    else if (param_2 < 0x31) {
      if (param_2 == 0x2a) {
        *(undefined1 *)((int)__ptr + 3) = 7;
        *(undefined1 *)(__ptr + 1) = 0x10;
      }
      else {
        if (param_2 != 0x2b) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 7;
        *(undefined1 *)(__ptr + 1) = 0x10;
      }
    }
    else {
      if (param_2 != 0x31) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x20;
    }
  }
  else if (param_2 == 0x43) {
    *(undefined1 *)((int)__ptr + 3) = 7;
    *(undefined1 *)(__ptr + 1) = 0x19;
  }
  else if (param_2 < 0x44) {
    if (param_2 == 0x40) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x19;
    }
    else if (param_2 < 0x41) {
      if (param_2 == 0x33) {
        *(undefined1 *)((int)__ptr + 3) = 7;
        *(undefined1 *)(__ptr + 1) = 0x10;
      }
      else {
        if (param_2 != 0x34) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 5;
        *(undefined1 *)(__ptr + 1) = 0x30;
      }
    }
    else if (param_2 == 0x41) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x19;
    }
    else {
      if (param_2 != 0x42) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x19;
    }
  }
  else if (param_2 == 0x46) {
    *(undefined1 *)((int)__ptr + 3) = 7;
    *(undefined1 *)(__ptr + 1) = 0x19;
  }
  else if (param_2 < 0x47) {
    if (param_2 == 0x44) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x19;
    }
    else {
      if (param_2 != 0x45) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x19;
    }
  }
  else {
    if (param_2 != 0x47) {
_L0:
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
      free(__ptr);
      return 0x102;
    }
    *(undefined1 *)((int)__ptr + 3) = 7;
    *(undefined1 *)(__ptr + 1) = 0x19;
  }
  __ptr[2] = 0xffff;
  __ptr[3] = (short)param_3;
  __ptr[4] = (short)((uint)param_3 >> 0x10);
  __ptr[5] = 0x101;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar1 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar1 + 0xc) = __ptr;
  }
  return 0;
}

