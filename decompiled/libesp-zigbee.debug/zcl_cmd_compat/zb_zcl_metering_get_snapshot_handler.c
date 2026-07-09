/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_metering_get_snapshot_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_get_snapshot_handler(undefined1 *param_1,code *param_2)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  void *pvVar5;
  uint uVar6;
  uint uVar7;
  undefined1 uStack_64;
  undefined1 uStack_63;
  undefined2 uStack_62;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  byte bStack_44;
  byte bStack_43;
  undefined1 auStack_42 [6];
  uint uStack_3c;
  byte bStack_38;
  byte bStack_37;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined4 uStack_30;
  undefined1 uStack_2c;
  byte bStack_2b;
  int iStack_2a;
  byte bStack_26;
  byte bStack_25;
  int iStack_24;
  
  memset(&uStack_64,0,0x44);
  uStack_64 = *param_1;
  uStack_63 = param_1[1];
  uStack_62 = *(undefined2 *)(param_1 + 2);
  uStack_60 = *(undefined4 *)(param_1 + 0xc);
  uStack_5c = *(undefined4 *)(param_1 + 0x10);
  uStack_58 = param_1[0x14];
  uStack_54 = *(undefined4 *)(param_1 + 0x18);
  if (param_2 != (code *)0x0) {
    (*param_2)(0x47,&uStack_64);
    uVar2 = esp_err_to_zcl_status();
    param_1[0x1c] = uVar2;
  }
  if (param_1[0x1c] == '\0') {
    puVar3 = (undefined4 *)calloc(1,0x40);
    *(undefined4 **)(param_1 + 0x20) = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
    }
    else {
      *puVar3 = uStack_50;
      *(undefined4 *)(*(int *)(param_1 + 0x20) + 4) = uStack_4c;
      *(undefined1 *)(*(int *)(param_1 + 0x20) + 8) = (undefined1)uStack_48;
      *(undefined1 *)(*(int *)(param_1 + 0x20) + 9) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x20) + 10) = 1;
      *(uint *)(*(int *)(param_1 + 0x20) + 0xc) = (uint)bStack_44 << 0x18 | uStack_48 >> 8;
      *(byte *)(*(int *)(param_1 + 0x20) + 0x10) = bStack_43;
      piVar4 = (int *)calloc(1,0xc);
      if (piVar4 == (int *)0x0) {
        esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
      }
      else {
        iVar1 = *(int *)(param_1 + 0x20);
        *piVar4 = iVar1;
        if (bStack_43 == 4) {
          array_copy_u48_to_u64(iVar1 + 0x18,auStack_42,1);
          uVar6 = uStack_3c & 0xff;
          *(undefined1 *)(iVar1 + 0x20) = (undefined1)uStack_3c;
          if ((uVar6 != 0) && (uVar7 = (uint)bStack_38 << 0x18 | uStack_3c >> 8, uVar7 != 0)) {
            pvVar5 = calloc(uVar6,8);
            if (pvVar5 == (void *)0x0) {
              esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
              return;
            }
            array_copy_u48_to_u64(uVar7,uVar6);
            *(void **)(iVar1 + 0x24) = pvVar5;
            piVar4[1] = (int)pvVar5;
          }
        }
        else if (bStack_43 < 5) {
          if (bStack_43 == 2) {
            array_copy_u48_to_u64(iVar1 + 0x18,auStack_42,1);
            *(uint *)(iVar1 + 0x20) = uStack_3c;
            *(uint *)(iVar1 + 0x24) = CONCAT22(uStack_36,CONCAT11(bStack_37,bStack_38));
            *(uint *)(iVar1 + 0x28) = CONCAT22(uStack_32,uStack_34);
            *(undefined4 *)(iVar1 + 0x2c) = uStack_30;
            *(undefined1 *)(iVar1 + 0x30) = uStack_2c;
            uVar6 = (uint)bStack_2b;
            *(byte *)(iVar1 + 0x31) = bStack_2b;
            if ((uVar6 != 0) && (iStack_2a != 0)) {
              pvVar5 = calloc(uVar6,8);
              if (pvVar5 == (void *)0x0) {
                esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
                return;
              }
              array_copy_u48_to_u64(iStack_2a,uVar6);
              *(void **)(iVar1 + 0x34) = pvVar5;
              piVar4[1] = (int)pvVar5;
            }
            uVar6 = (uint)bStack_26;
            *(byte *)(iVar1 + 0x38) = bStack_26;
            if ((uVar6 != 0) && (uVar7 = iStack_24 << 8 | (uint)bStack_25, uVar7 != 0)) {
              pvVar5 = calloc(uVar6,8);
              if (pvVar5 == (void *)0x0) {
                esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
                return;
              }
              array_copy_u48_to_u64(uVar7,uVar6);
              *(void **)(iVar1 + 0x3c) = pvVar5;
              piVar4[2] = (int)pvVar5;
            }
          }
          else if (bStack_43 < 3) {
            if (bStack_43 == 0) {
              array_copy_u48_to_u64(iVar1 + 0x18,auStack_42,1);
              *(uint *)(iVar1 + 0x20) = uStack_3c;
              *(uint *)(iVar1 + 0x24) = CONCAT22(uStack_36,CONCAT11(bStack_37,bStack_38));
              *(uint *)(iVar1 + 0x28) = CONCAT22(uStack_32,uStack_34);
              *(undefined4 *)(iVar1 + 0x2c) = uStack_30;
              *(undefined1 *)(iVar1 + 0x30) = uStack_2c;
              uVar6 = (uint)bStack_2b;
              *(byte *)(iVar1 + 0x31) = bStack_2b;
              if ((uVar6 != 0) && (iStack_2a != 0)) {
                pvVar5 = calloc(uVar6,8);
                if (pvVar5 == (void *)0x0) {
                  esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
                  return;
                }
                array_copy_u48_to_u64(iStack_2a,uVar6);
                *(void **)(iVar1 + 0x34) = pvVar5;
                piVar4[1] = (int)pvVar5;
              }
            }
            else if (bStack_43 == 1) {
              array_copy_u48_to_u64(iVar1 + 0x18,auStack_42,1);
              *(uint *)(iVar1 + 0x20) = uStack_3c;
              *(uint *)(iVar1 + 0x24) = CONCAT22(uStack_36,CONCAT11(bStack_37,bStack_38));
              *(uint *)(iVar1 + 0x28) = CONCAT22(uStack_32,uStack_34);
              *(undefined4 *)(iVar1 + 0x2c) = uStack_30;
              *(undefined1 *)(iVar1 + 0x30) = uStack_2c;
              uVar6 = (uint)bStack_2b;
              *(byte *)(iVar1 + 0x31) = bStack_2b;
              if ((uVar6 != 0) && (iStack_2a != 0)) {
                pvVar5 = calloc(uVar6,8);
                if (pvVar5 == (void *)0x0) {
                  esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
                  return;
                }
                array_copy_u48_to_u64(iStack_2a,uVar6);
                *(void **)(iVar1 + 0x34) = pvVar5;
                piVar4[1] = (int)pvVar5;
              }
            }
          }
          else if (bStack_43 == 3) {
            array_copy_u48_to_u64(iVar1 + 0x18,auStack_42,1);
            *(uint *)(iVar1 + 0x20) = uStack_3c;
            *(uint *)(iVar1 + 0x24) = CONCAT22(uStack_36,CONCAT11(bStack_37,bStack_38));
            *(uint *)(iVar1 + 0x28) = CONCAT22(uStack_32,uStack_34);
            *(undefined4 *)(iVar1 + 0x2c) = uStack_30;
            *(undefined1 *)(iVar1 + 0x30) = uStack_2c;
            uVar6 = (uint)bStack_2b;
            *(byte *)(iVar1 + 0x31) = bStack_2b;
            if ((uVar6 != 0) && (iStack_2a != 0)) {
              pvVar5 = calloc(uVar6,8);
              if (pvVar5 == (void *)0x0) {
                esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
                return;
              }
              array_copy_u48_to_u64(iStack_2a,uVar6);
              *(void **)(iVar1 + 0x34) = pvVar5;
              piVar4[1] = (int)pvVar5;
            }
            uVar6 = (uint)bStack_26;
            *(byte *)(iVar1 + 0x38) = bStack_26;
            if ((uVar6 != 0) && (uVar7 = iStack_24 << 8 | (uint)bStack_25, uVar7 != 0)) {
              pvVar5 = calloc(uVar6,8);
              if (pvVar5 == (void *)0x0) {
                esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
                return;
              }
              array_copy_u48_to_u64(uVar7,uVar6);
              *(void **)(iVar1 + 0x3c) = pvVar5;
              piVar4[2] = (int)pvVar5;
            }
          }
        }
        else if (bStack_43 == 6) {
          array_copy_u48_to_u64(iVar1 + 0x18,auStack_42,1);
          uVar6 = uStack_3c & 0xff;
          *(undefined1 *)(iVar1 + 0x20) = (undefined1)uStack_3c;
          if ((uVar6 != 0) && (uVar7 = (uint)bStack_38 << 0x18 | uStack_3c >> 8, uVar7 != 0)) {
            pvVar5 = calloc(uVar6,8);
            if (pvVar5 == (void *)0x0) {
              esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
              return;
            }
            array_copy_u48_to_u64(uVar7,uVar6);
            *(void **)(iVar1 + 0x24) = pvVar5;
            piVar4[1] = (int)pvVar5;
          }
          uVar6 = (uint)bStack_37;
          *(byte *)(iVar1 + 0x28) = bStack_37;
          if ((uVar6 != 0) && (CONCAT22(uStack_34,uStack_36) != 0)) {
            pvVar5 = calloc(uVar6,8);
            if (pvVar5 == (void *)0x0) {
              esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
              return;
            }
            array_copy_u48_to_u64(CONCAT22(uStack_34,uStack_36),uVar6);
            *(void **)(iVar1 + 0x2c) = pvVar5;
            piVar4[2] = (int)pvVar5;
          }
        }
        else if (bStack_43 == 7) {
          array_copy_u48_to_u64(iVar1 + 0x18,auStack_42,1);
          uVar6 = uStack_3c & 0xff;
          *(undefined1 *)(iVar1 + 0x20) = (undefined1)uStack_3c;
          if ((uVar6 != 0) && (uVar7 = (uint)bStack_38 << 0x18 | uStack_3c >> 8, uVar7 != 0)) {
            pvVar5 = calloc(uVar6,8);
            if (pvVar5 == (void *)0x0) {
              esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
              return;
            }
            array_copy_u48_to_u64(uVar7,uVar6);
            *(void **)(iVar1 + 0x24) = pvVar5;
            piVar4[1] = (int)pvVar5;
          }
          uVar6 = (uint)bStack_37;
          *(byte *)(iVar1 + 0x28) = bStack_37;
          if ((uVar6 != 0) && (CONCAT22(uStack_34,uStack_36) != 0)) {
            pvVar5 = calloc(uVar6,8);
            if (pvVar5 == (void *)0x0) {
              esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
              return;
            }
            array_copy_u48_to_u64(CONCAT22(uStack_34,uStack_36),uVar6);
            *(void **)(iVar1 + 0x2c) = pvVar5;
            piVar4[2] = (int)pvVar5;
          }
        }
        else if (bStack_43 == 5) {
          array_copy_u48_to_u64(iVar1 + 0x18,auStack_42,1);
          uVar6 = uStack_3c & 0xff;
          *(undefined1 *)(iVar1 + 0x20) = (undefined1)uStack_3c;
          if ((uVar6 != 0) && (uVar7 = (uint)bStack_38 << 0x18 | uStack_3c >> 8, uVar7 != 0)) {
            pvVar5 = calloc(uVar6,8);
            if (pvVar5 == (void *)0x0) {
              esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
              return;
            }
            array_copy_u48_to_u64(uVar7,uVar6);
            *(void **)(iVar1 + 0x24) = pvVar5;
            piVar4[1] = (int)pvVar5;
          }
        }
        *(code **)(param_1 + 0x24) = free_metering_snapshot_mem;
        *(int **)(param_1 + 0x28) = piVar4;
      }
    }
  }
  else if (*(void **)(param_1 + 0x20) != (void *)0x0) {
    free(*(void **)(param_1 + 0x20));
  }
  return;
}

