/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_metering_publish_snapshot_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_publish_snapshot_handler(undefined4 *param_1,code *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  void *__ptr;
  void *pvVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_40 = 0;
  uStack_3c = (void *)0x0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_58 = *param_1;
  uStack_54 = param_1[4];
  uStack_50 = param_1[5];
  uStack_4c = (uint)*(uint3 *)(param_1 + 6);
  uStack_48 = param_1[7];
  bVar1 = *(byte *)(param_1 + 8);
  uStack_44 = (uint)bVar1;
  if (bVar1 == 4) {
    array_copy_u64_to_u48((int)&uStack_44 + 1,param_1 + 10,1);
    uVar6 = (uint)*(byte *)(param_1 + 0xc);
    uStack_40 = CONCAT13(*(byte *)(param_1 + 0xc),(undefined3)uStack_40);
    if (uVar6 == 0) {
      pvVar5 = (void *)0x0;
      __ptr = (void *)0x0;
    }
    else {
      iVar4 = param_1[0xd];
      if (iVar4 == 0) {
        __ptr = (void *)0x0;
        pvVar5 = (void *)0x0;
      }
      else {
        __ptr = calloc(uVar6,6);
        if (__ptr == (void *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u64_to_u48(iVar4,uVar6);
        pvVar5 = (void *)0x0;
        uStack_3c = __ptr;
      }
    }
  }
  else if (bVar1 < 5) {
    if (bVar1 == 2) {
      array_copy_u64_to_u48((int)&uStack_44 + 1,param_1 + 10,1);
      uStack_40 = CONCAT13((char)param_1[0xc],(undefined3)uStack_40);
      uStack_3c._0_3_ = (undefined3)((uint)param_1[0xc] >> 8);
      uStack_3c = (void *)CONCAT13((char)param_1[0xd],(undefined3)uStack_3c);
      uStack_38._0_3_ = (undefined3)((uint)param_1[0xd] >> 8);
      uStack_38 = CONCAT13((char)param_1[0xe],(undefined3)uStack_38);
      uStack_34._0_3_ = (undefined3)((uint)param_1[0xe] >> 8);
      uStack_34 = CONCAT13((char)param_1[0xf],(undefined3)uStack_34);
      uStack_30._0_3_ = (undefined3)((uint)param_1[0xf] >> 8);
      uStack_30 = CONCAT13(*(undefined1 *)(param_1 + 0x10),(undefined3)uStack_30);
      uVar6 = (uint)*(byte *)((int)param_1 + 0x41);
      uStack_2c = CONCAT31(uStack_2c._1_3_,*(byte *)((int)param_1 + 0x41));
      if (uVar6 == 0) {
        __ptr = (void *)0x0;
      }
      else {
        pvVar5 = (void *)param_1[0x11];
        __ptr = pvVar5;
        if (pvVar5 != (void *)0x0) {
          __ptr = calloc(uVar6,6);
          if (__ptr == (void *)0x0) {
            esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
            return;
          }
          array_copy_u64_to_u48(pvVar5,uVar6);
          uStack_2c._0_2_ = CONCAT11((char)__ptr,(undefined1)uStack_2c);
          uStack_2c._0_3_ = CONCAT12((char)((uint)__ptr >> 8),(undefined2)uStack_2c);
          uStack_2c = CONCAT13((char)((uint)__ptr >> 0x10),(undefined3)uStack_2c);
          uStack_28 = CONCAT31(uStack_28._1_3_,(char)((uint)__ptr >> 0x18));
        }
      }
      uVar6 = (uint)*(byte *)(param_1 + 0x12);
      uStack_28._0_2_ = CONCAT11(*(byte *)(param_1 + 0x12),(undefined1)uStack_28);
      if (uVar6 == 0) {
        pvVar5 = (void *)0x0;
      }
      else {
        pvVar5 = (void *)param_1[0x13];
        if (pvVar5 != (void *)0x0) {
          pvVar3 = calloc(uVar6,6);
          if (pvVar3 == (void *)0x0) {
            esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
            return;
          }
          array_copy_u64_to_u48(pvVar5,uVar6);
          uStack_28 = CONCAT22((short)pvVar3,(undefined2)uStack_28);
          uStack_24 = CONCAT22(uStack_24._2_2_,(short)((uint)pvVar3 >> 0x10));
          pvVar5 = pvVar3;
        }
      }
    }
    else if (bVar1 < 3) {
      if (bVar1 == 0) {
        array_copy_u64_to_u48((int)&uStack_44 + 1,param_1 + 10,1);
        uStack_40 = CONCAT13((char)param_1[0xc],(undefined3)uStack_40);
        uStack_3c._0_3_ = (undefined3)((uint)param_1[0xc] >> 8);
        uStack_3c = (void *)CONCAT13((char)param_1[0xd],(undefined3)uStack_3c);
        uStack_38._0_3_ = (undefined3)((uint)param_1[0xd] >> 8);
        uStack_38 = CONCAT13((char)param_1[0xe],(undefined3)uStack_38);
        uStack_34._0_3_ = (undefined3)((uint)param_1[0xe] >> 8);
        uStack_34 = CONCAT13((char)param_1[0xf],(undefined3)uStack_34);
        uStack_30._0_3_ = (undefined3)((uint)param_1[0xf] >> 8);
        uStack_30 = CONCAT13(*(undefined1 *)(param_1 + 0x10),(undefined3)uStack_30);
        uVar6 = (uint)*(byte *)((int)param_1 + 0x41);
        uStack_2c = CONCAT31(uStack_2c._1_3_,*(byte *)((int)param_1 + 0x41));
        if (uVar6 == 0) {
          __ptr = (void *)0x0;
          pvVar5 = (void *)0x0;
        }
        else {
          iVar4 = param_1[0x11];
          if (iVar4 == 0) {
            __ptr = (void *)0x0;
            pvVar5 = (void *)0x0;
          }
          else {
            __ptr = calloc(uVar6,6);
            if (__ptr == (void *)0x0) {
              esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
              return;
            }
            array_copy_u64_to_u48(iVar4,uVar6);
            uStack_2c._0_2_ = CONCAT11((char)__ptr,(undefined1)uStack_2c);
            uStack_2c._0_3_ = CONCAT12((char)((uint)__ptr >> 8),(undefined2)uStack_2c);
            uStack_2c = CONCAT13((char)((uint)__ptr >> 0x10),(undefined3)uStack_2c);
            uStack_28 = CONCAT31(uStack_28._1_3_,(char)((uint)__ptr >> 0x18));
            pvVar5 = (void *)0x0;
          }
        }
      }
      else {
        if (bVar1 != 1) goto _L0;
        array_copy_u64_to_u48((int)&uStack_44 + 1,param_1 + 10,1);
        uStack_40 = CONCAT13((char)param_1[0xc],(undefined3)uStack_40);
        uStack_3c._0_3_ = (undefined3)((uint)param_1[0xc] >> 8);
        uStack_3c = (void *)CONCAT13((char)param_1[0xd],(undefined3)uStack_3c);
        uStack_38._0_3_ = (undefined3)((uint)param_1[0xd] >> 8);
        uStack_38 = CONCAT13((char)param_1[0xe],(undefined3)uStack_38);
        uStack_34._0_3_ = (undefined3)((uint)param_1[0xe] >> 8);
        uStack_34 = CONCAT13((char)param_1[0xf],(undefined3)uStack_34);
        uStack_30._0_3_ = (undefined3)((uint)param_1[0xf] >> 8);
        uStack_30 = CONCAT13(*(undefined1 *)(param_1 + 0x10),(undefined3)uStack_30);
        uVar6 = (uint)*(byte *)((int)param_1 + 0x41);
        uStack_2c = CONCAT31(uStack_2c._1_3_,*(byte *)((int)param_1 + 0x41));
        if (uVar6 == 0) {
          __ptr = (void *)0x0;
          pvVar5 = (void *)0x0;
        }
        else {
          iVar4 = param_1[0x11];
          if (iVar4 == 0) {
            __ptr = (void *)0x0;
            pvVar5 = (void *)0x0;
          }
          else {
            __ptr = calloc(uVar6,6);
            if (__ptr == (void *)0x0) {
              esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
              return;
            }
            array_copy_u64_to_u48(iVar4,uVar6);
            uStack_2c._0_2_ = CONCAT11((char)__ptr,(undefined1)uStack_2c);
            uStack_2c._0_3_ = CONCAT12((char)((uint)__ptr >> 8),(undefined2)uStack_2c);
            uStack_2c = CONCAT13((char)((uint)__ptr >> 0x10),(undefined3)uStack_2c);
            uStack_28 = CONCAT31(uStack_28._1_3_,(char)((uint)__ptr >> 0x18));
            pvVar5 = (void *)0x0;
          }
        }
      }
    }
    else {
      if (bVar1 != 3) {
_L0:
        *(undefined1 *)(param_1 + 0x14) = 0x87;
        return;
      }
      array_copy_u64_to_u48((int)&uStack_44 + 1,param_1 + 10,1);
      uStack_40 = CONCAT13((char)param_1[0xc],(undefined3)uStack_40);
      uStack_3c._0_3_ = (undefined3)((uint)param_1[0xc] >> 8);
      uStack_3c = (void *)CONCAT13((char)param_1[0xd],(undefined3)uStack_3c);
      uStack_38._0_3_ = (undefined3)((uint)param_1[0xd] >> 8);
      uStack_38 = CONCAT13((char)param_1[0xe],(undefined3)uStack_38);
      uStack_34._0_3_ = (undefined3)((uint)param_1[0xe] >> 8);
      uStack_34 = CONCAT13((char)param_1[0xf],(undefined3)uStack_34);
      uStack_30._0_3_ = (undefined3)((uint)param_1[0xf] >> 8);
      uStack_30 = CONCAT13(*(undefined1 *)(param_1 + 0x10),(undefined3)uStack_30);
      uVar6 = (uint)*(byte *)((int)param_1 + 0x41);
      uStack_2c = CONCAT31(uStack_2c._1_3_,*(byte *)((int)param_1 + 0x41));
      if (uVar6 == 0) {
        __ptr = (void *)0x0;
      }
      else {
        pvVar5 = (void *)param_1[0x11];
        __ptr = pvVar5;
        if (pvVar5 != (void *)0x0) {
          __ptr = calloc(uVar6,6);
          if (__ptr == (void *)0x0) {
            esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
            return;
          }
          array_copy_u64_to_u48(pvVar5,uVar6);
          uStack_2c._0_2_ = CONCAT11((char)__ptr,(undefined1)uStack_2c);
          uStack_2c._0_3_ = CONCAT12((char)((uint)__ptr >> 8),(undefined2)uStack_2c);
          uStack_2c = CONCAT13((char)((uint)__ptr >> 0x10),(undefined3)uStack_2c);
          uStack_28 = CONCAT31(uStack_28._1_3_,(char)((uint)__ptr >> 0x18));
        }
      }
      uVar6 = (uint)*(byte *)(param_1 + 0x12);
      uStack_28._0_2_ = CONCAT11(*(byte *)(param_1 + 0x12),(undefined1)uStack_28);
      if (uVar6 == 0) {
        pvVar5 = (void *)0x0;
      }
      else {
        pvVar5 = (void *)param_1[0x13];
        if (pvVar5 != (void *)0x0) {
          pvVar3 = calloc(uVar6,6);
          if (pvVar3 == (void *)0x0) {
            esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
            return;
          }
          array_copy_u64_to_u48(pvVar5,uVar6);
          uStack_28 = CONCAT22((short)pvVar3,(undefined2)uStack_28);
          uStack_24 = CONCAT22(uStack_24._2_2_,(short)((uint)pvVar3 >> 0x10));
          pvVar5 = pvVar3;
        }
      }
    }
  }
  else if (bVar1 == 6) {
    array_copy_u64_to_u48((int)&uStack_44 + 1,param_1 + 10,1);
    uVar6 = (uint)*(byte *)(param_1 + 0xc);
    uStack_40 = CONCAT13(*(byte *)(param_1 + 0xc),(undefined3)uStack_40);
    if (uVar6 == 0) {
      __ptr = (void *)0x0;
    }
    else {
      pvVar5 = (void *)param_1[0xd];
      __ptr = pvVar5;
      if (pvVar5 != (void *)0x0) {
        __ptr = calloc(uVar6,6);
        if (__ptr == (void *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u64_to_u48(pvVar5,uVar6);
        uStack_3c = __ptr;
      }
    }
    uVar6 = (uint)*(byte *)(param_1 + 0xe);
    uStack_38 = CONCAT31(uStack_38._1_3_,*(byte *)(param_1 + 0xe));
    if (uVar6 == 0) {
      pvVar5 = (void *)0x0;
    }
    else {
      pvVar3 = (void *)param_1[0xf];
      pvVar5 = pvVar3;
      if (pvVar3 != (void *)0x0) {
        pvVar5 = calloc(uVar6,6);
        if (pvVar5 == (void *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u64_to_u48(pvVar3,uVar6);
        uStack_38._0_2_ = CONCAT11((char)pvVar5,(undefined1)uStack_38);
        uStack_38._0_3_ = CONCAT12((char)((uint)pvVar5 >> 8),(undefined2)uStack_38);
        uStack_38 = CONCAT13((char)((uint)pvVar5 >> 0x10),(undefined3)uStack_38);
        uStack_34 = CONCAT31(uStack_34._1_3_,(char)((uint)pvVar5 >> 0x18));
      }
    }
  }
  else if (bVar1 == 7) {
    array_copy_u64_to_u48((int)&uStack_44 + 1,param_1 + 10,1);
    uVar6 = (uint)*(byte *)(param_1 + 0xc);
    uStack_40 = CONCAT13(*(byte *)(param_1 + 0xc),(undefined3)uStack_40);
    if (uVar6 == 0) {
      __ptr = (void *)0x0;
    }
    else {
      pvVar5 = (void *)param_1[0xd];
      __ptr = pvVar5;
      if (pvVar5 != (void *)0x0) {
        __ptr = calloc(uVar6,6);
        if (__ptr == (void *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u64_to_u48(pvVar5,uVar6);
        uStack_3c = __ptr;
      }
    }
    uVar6 = (uint)*(byte *)(param_1 + 0xe);
    uStack_38 = CONCAT31(uStack_38._1_3_,*(byte *)(param_1 + 0xe));
    if (uVar6 == 0) {
      pvVar5 = (void *)0x0;
    }
    else {
      pvVar5 = (void *)param_1[0xf];
      if (pvVar5 != (void *)0x0) {
        pvVar3 = calloc(uVar6,6);
        if (pvVar3 == (void *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u64_to_u48(pvVar5,uVar6);
        uStack_38._0_2_ = CONCAT11((char)pvVar3,(undefined1)uStack_38);
        uStack_38._0_3_ = CONCAT12((char)((uint)pvVar3 >> 8),(undefined2)uStack_38);
        uStack_38 = CONCAT13((char)((uint)pvVar3 >> 0x10),(undefined3)uStack_38);
        uStack_34 = CONCAT31(uStack_34._1_3_,(char)((uint)pvVar3 >> 0x18));
        pvVar5 = pvVar3;
      }
    }
  }
  else {
    if (bVar1 != 5) goto _L0;
    array_copy_u64_to_u48((int)&uStack_44 + 1,param_1 + 10,1);
    uVar6 = (uint)*(byte *)(param_1 + 0xc);
    uStack_40 = CONCAT13(*(byte *)(param_1 + 0xc),(undefined3)uStack_40);
    if (uVar6 == 0) {
      __ptr = (void *)0x0;
      pvVar5 = (void *)0x0;
    }
    else {
      iVar4 = param_1[0xd];
      if (iVar4 == 0) {
        __ptr = (void *)0x0;
        pvVar5 = (void *)0x0;
      }
      else {
        __ptr = calloc(uVar6,6);
        if (__ptr == (void *)0x0) {
          esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
          return;
        }
        array_copy_u64_to_u48(iVar4,uVar6);
        pvVar5 = (void *)0x0;
        uStack_3c = __ptr;
      }
    }
  }
  if (param_2 != (code *)0x0) {
    (*param_2)(0x48,&uStack_58);
    uVar2 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 0x14) = uVar2;
  }
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  if (pvVar5 != (void *)0x0) {
    free(pvVar5);
  }
  return;
}

