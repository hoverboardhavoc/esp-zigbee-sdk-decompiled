/*
 * Last changed at upstream commit 503c5e49627f84174ce142bf784c3f01532fb5c9
 * https://github.com/espressif/esp-zigbee-sdk/commit/503c5e49627f84174ce142bf784c3f01532fb5c9
 * Upstream date: 2023-06-05 10:37:46 +0800
 * Upstream subject: esp-zigbee-sdk: optimize the zigbee cluster implementation(0f0acd4)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_door_lock_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_door_lock_cluster_add_attr(int param_1,uint param_2,char *param_3)

{
  undefined2 *__ptr;
  int iVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  char *pcVar4;
  size_t sVar5;
  undefined4 uVar6;
  int aiStack_24 [2];
  
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
    puVar3 = (undefined4 *)malloc(4);
    *puVar3 = *(undefined4 *)param_3;
    __ptr[3] = (short)puVar3;
    __ptr[4] = (short)((uint)puVar3 >> 0x10);
  }
  else if (param_2 < 0x24) {
    if (param_2 == 0x13) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar2 = (undefined2 *)malloc(2);
      *puVar2 = *(undefined2 *)param_3;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
    }
    else if (param_2 < 0x14) {
      if (param_2 == 5) {
        *(undefined1 *)((int)__ptr + 3) = 3;
        *(undefined1 *)(__ptr + 1) = 0x23;
        puVar3 = (undefined4 *)malloc(4);
        *puVar3 = *(undefined4 *)param_3;
        __ptr[3] = (short)puVar3;
        __ptr[4] = (short)((uint)puVar3 >> 0x10);
      }
      else if (param_2 < 6) {
        if (param_2 == 2) {
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x10;
          pcVar4 = (char *)malloc(1);
          *pcVar4 = *param_3;
          __ptr[3] = (short)pcVar4;
          __ptr[4] = (short)((uint)pcVar4 >> 0x10);
        }
        else if (param_2 < 3) {
          if (param_2 == 0) {
            *(undefined1 *)((int)__ptr + 3) = 5;
            *(undefined1 *)(__ptr + 1) = 0x30;
            pcVar4 = (char *)malloc(1);
            *pcVar4 = *param_3;
            __ptr[3] = (short)pcVar4;
            __ptr[4] = (short)((uint)pcVar4 >> 0x10);
          }
          else {
            if (param_2 != 1) goto _L0;
            *(undefined1 *)((int)__ptr + 3) = 1;
            *(undefined1 *)(__ptr + 1) = 0x30;
            pcVar4 = (char *)malloc(1);
            *pcVar4 = *param_3;
            __ptr[3] = (short)pcVar4;
            __ptr[4] = (short)((uint)pcVar4 >> 0x10);
          }
        }
        else if (param_2 == 3) {
          *(undefined1 *)((int)__ptr + 3) = 5;
          *(undefined1 *)(__ptr + 1) = 0x30;
          pcVar4 = (char *)malloc(1);
          *pcVar4 = *param_3;
          __ptr[3] = (short)pcVar4;
          __ptr[4] = (short)((uint)pcVar4 >> 0x10);
        }
        else {
          if (param_2 != 4) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 3;
          *(undefined1 *)(__ptr + 1) = 0x23;
          puVar3 = (undefined4 *)malloc(4);
          *puVar3 = *(undefined4 *)param_3;
          __ptr[3] = (short)puVar3;
          __ptr[4] = (short)((uint)puVar3 >> 0x10);
        }
      }
      else if (param_2 == 0x11) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x21;
        puVar2 = (undefined2 *)malloc(2);
        *puVar2 = *(undefined2 *)param_3;
        __ptr[3] = (short)puVar2;
        __ptr[4] = (short)((uint)puVar2 >> 0x10);
      }
      else if (param_2 < 0x12) {
        if (param_2 == 6) {
          *(undefined1 *)((int)__ptr + 3) = 3;
          *(undefined1 *)(__ptr + 1) = 0x21;
          puVar2 = (undefined2 *)malloc(2);
          *puVar2 = *(undefined2 *)param_3;
          __ptr[3] = (short)puVar2;
          __ptr[4] = (short)((uint)puVar2 >> 0x10);
        }
        else {
          if (param_2 != 0x10) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x21;
          puVar2 = (undefined2 *)malloc(2);
          *puVar2 = *(undefined2 *)param_3;
          __ptr[3] = (short)puVar2;
          __ptr[4] = (short)((uint)puVar2 >> 0x10);
        }
      }
      else {
        if (param_2 != 0x12) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x21;
        puVar2 = (undefined2 *)malloc(2);
        *puVar2 = *(undefined2 *)param_3;
        __ptr[3] = (short)puVar2;
        __ptr[4] = (short)((uint)puVar2 >> 0x10);
      }
    }
    else if (param_2 == 0x19) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x20;
      pcVar4 = (char *)malloc(1);
      *pcVar4 = *param_3;
      __ptr[3] = (short)pcVar4;
      __ptr[4] = (short)((uint)pcVar4 >> 0x10);
    }
    else if (param_2 < 0x1a) {
      if (param_2 == 0x16) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
        pcVar4 = (char *)malloc(1);
        *pcVar4 = *param_3;
        __ptr[3] = (short)pcVar4;
        __ptr[4] = (short)((uint)pcVar4 >> 0x10);
      }
      else if (param_2 < 0x17) {
        if (param_2 == 0x14) {
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x20;
          pcVar4 = (char *)malloc(1);
          *pcVar4 = *param_3;
          __ptr[3] = (short)pcVar4;
          __ptr[4] = (short)((uint)pcVar4 >> 0x10);
        }
        else {
          if (param_2 != 0x15) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x20;
          pcVar4 = (char *)malloc(1);
          *pcVar4 = *param_3;
          __ptr[3] = (short)pcVar4;
          __ptr[4] = (short)((uint)pcVar4 >> 0x10);
        }
      }
      else if (param_2 == 0x17) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
        pcVar4 = (char *)malloc(1);
        *pcVar4 = *param_3;
        __ptr[3] = (short)pcVar4;
        __ptr[4] = (short)((uint)pcVar4 >> 0x10);
      }
      else {
        if (param_2 != 0x18) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
        pcVar4 = (char *)malloc(1);
        *pcVar4 = *param_3;
        __ptr[3] = (short)pcVar4;
        __ptr[4] = (short)((uint)pcVar4 >> 0x10);
      }
    }
    else if (param_2 == 0x21) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x42;
      sVar5 = strlen(param_3);
      pcVar4 = (char *)malloc(sVar5 + 1);
      strcpy(pcVar4,param_3);
      __ptr[3] = (short)pcVar4;
      __ptr[4] = (short)((uint)pcVar4 >> 0x10);
    }
    else if (param_2 < 0x22) {
      if (param_2 == 0x1a) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
        pcVar4 = (char *)malloc(1);
        *pcVar4 = *param_3;
        __ptr[3] = (short)pcVar4;
        __ptr[4] = (short)((uint)pcVar4 >> 0x10);
      }
      else {
        if (param_2 != 0x20) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 7;
        *(undefined1 *)(__ptr + 1) = 0x10;
        pcVar4 = (char *)malloc(1);
        *pcVar4 = *param_3;
        __ptr[3] = (short)pcVar4;
        __ptr[4] = (short)((uint)pcVar4 >> 0x10);
      }
    }
    else {
      if (param_2 != 0x22) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x20;
      pcVar4 = (char *)malloc(1);
      *pcVar4 = *param_3;
      __ptr[3] = (short)pcVar4;
      __ptr[4] = (short)((uint)pcVar4 >> 0x10);
    }
  }
  else if (param_2 == 0x32) {
    *(undefined1 *)((int)__ptr + 3) = 7;
    *(undefined1 *)(__ptr + 1) = 0x10;
    pcVar4 = (char *)malloc(1);
    *pcVar4 = *param_3;
    __ptr[3] = (short)pcVar4;
    __ptr[4] = (short)((uint)pcVar4 >> 0x10);
  }
  else if (param_2 < 0x33) {
    if (param_2 == 0x29) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x10;
      pcVar4 = (char *)malloc(1);
      *pcVar4 = *param_3;
      __ptr[3] = (short)pcVar4;
      __ptr[4] = (short)((uint)pcVar4 >> 0x10);
    }
    else if (param_2 < 0x2a) {
      if (param_2 == 0x26) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x19;
        puVar2 = (undefined2 *)malloc(2);
        *puVar2 = *(undefined2 *)param_3;
        __ptr[3] = (short)puVar2;
        __ptr[4] = (short)((uint)puVar2 >> 0x10);
      }
      else if (param_2 < 0x27) {
        if (param_2 == 0x24) {
          *(undefined1 *)((int)__ptr + 3) = 7;
          *(undefined1 *)(__ptr + 1) = 0x20;
          pcVar4 = (char *)malloc(1);
          *pcVar4 = *param_3;
          __ptr[3] = (short)pcVar4;
          __ptr[4] = (short)((uint)pcVar4 >> 0x10);
        }
        else {
          if (param_2 != 0x25) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 7;
          *(undefined1 *)(__ptr + 1) = 0x30;
          pcVar4 = (char *)malloc(1);
          *pcVar4 = *param_3;
          __ptr[3] = (short)pcVar4;
          __ptr[4] = (short)((uint)pcVar4 >> 0x10);
        }
      }
      else if (param_2 == 0x27) {
        *(undefined1 *)((int)__ptr + 3) = 5;
        *(undefined1 *)(__ptr + 1) = 0x19;
        puVar2 = (undefined2 *)malloc(2);
        *puVar2 = *(undefined2 *)param_3;
        __ptr[3] = (short)puVar2;
        __ptr[4] = (short)((uint)puVar2 >> 0x10);
      }
      else {
        if (param_2 != 0x28) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 7;
        *(undefined1 *)(__ptr + 1) = 0x10;
        pcVar4 = (char *)malloc(1);
        *pcVar4 = *param_3;
        __ptr[3] = (short)pcVar4;
        __ptr[4] = (short)((uint)pcVar4 >> 0x10);
      }
    }
    else if (param_2 == 0x30) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x20;
      pcVar4 = (char *)malloc(1);
      *pcVar4 = *param_3;
      __ptr[3] = (short)pcVar4;
      __ptr[4] = (short)((uint)pcVar4 >> 0x10);
    }
    else if (param_2 < 0x31) {
      if (param_2 == 0x2a) {
        *(undefined1 *)((int)__ptr + 3) = 7;
        *(undefined1 *)(__ptr + 1) = 0x10;
        pcVar4 = (char *)malloc(1);
        *pcVar4 = *param_3;
        __ptr[3] = (short)pcVar4;
        __ptr[4] = (short)((uint)pcVar4 >> 0x10);
      }
      else {
        if (param_2 != 0x2b) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 7;
        *(undefined1 *)(__ptr + 1) = 0x10;
        pcVar4 = (char *)malloc(1);
        *pcVar4 = *param_3;
        __ptr[3] = (short)pcVar4;
        __ptr[4] = (short)((uint)pcVar4 >> 0x10);
      }
    }
    else {
      if (param_2 != 0x31) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x20;
      pcVar4 = (char *)malloc(1);
      *pcVar4 = *param_3;
      __ptr[3] = (short)pcVar4;
      __ptr[4] = (short)((uint)pcVar4 >> 0x10);
    }
  }
  else if (param_2 == 0x43) {
    *(undefined1 *)((int)__ptr + 3) = 7;
    *(undefined1 *)(__ptr + 1) = 0x19;
    puVar2 = (undefined2 *)malloc(2);
    *puVar2 = *(undefined2 *)param_3;
    __ptr[3] = (short)puVar2;
    __ptr[4] = (short)((uint)puVar2 >> 0x10);
  }
  else if (param_2 < 0x44) {
    if (param_2 == 0x40) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x19;
      puVar2 = (undefined2 *)malloc(2);
      *puVar2 = *(undefined2 *)param_3;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
    }
    else if (param_2 < 0x41) {
      if (param_2 == 0x33) {
        *(undefined1 *)((int)__ptr + 3) = 7;
        *(undefined1 *)(__ptr + 1) = 0x10;
        pcVar4 = (char *)malloc(1);
        *pcVar4 = *param_3;
        __ptr[3] = (short)pcVar4;
        __ptr[4] = (short)((uint)pcVar4 >> 0x10);
      }
      else {
        if (param_2 != 0x34) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 5;
        *(undefined1 *)(__ptr + 1) = 0x30;
        pcVar4 = (char *)malloc(1);
        *pcVar4 = *param_3;
        __ptr[3] = (short)pcVar4;
        __ptr[4] = (short)((uint)pcVar4 >> 0x10);
      }
    }
    else if (param_2 == 0x41) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x19;
      puVar2 = (undefined2 *)malloc(2);
      *puVar2 = *(undefined2 *)param_3;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
    }
    else {
      if (param_2 != 0x42) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x19;
      puVar2 = (undefined2 *)malloc(2);
      *puVar2 = *(undefined2 *)param_3;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
    }
  }
  else if (param_2 == 0x46) {
    *(undefined1 *)((int)__ptr + 3) = 7;
    *(undefined1 *)(__ptr + 1) = 0x19;
    puVar2 = (undefined2 *)malloc(2);
    *puVar2 = *(undefined2 *)param_3;
    __ptr[3] = (short)puVar2;
    __ptr[4] = (short)((uint)puVar2 >> 0x10);
  }
  else if (param_2 < 0x47) {
    if (param_2 == 0x44) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x19;
      puVar2 = (undefined2 *)malloc(2);
      *puVar2 = *(undefined2 *)param_3;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
    }
    else {
      if (param_2 != 0x45) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x19;
      puVar2 = (undefined2 *)malloc(2);
      *puVar2 = *(undefined2 *)param_3;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
    }
  }
  else {
    if (param_2 != 0x47) {
_L0:
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar6,"ESP_ZIGBEE_ATTRIBUTE");
      free(__ptr);
      return 0x102;
    }
    *(undefined1 *)((int)__ptr + 3) = 7;
    *(undefined1 *)(__ptr + 1) = 0x19;
    puVar2 = (undefined2 *)malloc(2);
    *puVar2 = *(undefined2 *)param_3;
    __ptr[3] = (short)puVar2;
    __ptr[4] = (short)((uint)puVar2 >> 0x10);
  }
  __ptr[2] = 0xffff;
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

