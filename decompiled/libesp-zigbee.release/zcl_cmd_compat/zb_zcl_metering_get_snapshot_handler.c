/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_get_snapshot_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_get_snapshot_handler(undefined2 *param_1,code *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *pvVar5;
  uint uVar6;
  undefined2 uStack_64;
  undefined2 uStack_62;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_58 [4];
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
  undefined2 uStack_2c;
  int iStack_2a;
  byte bStack_26;
  byte bStack_25;
  int iStack_24;
  
  memset(auStack_58,0,0x38);
  uStack_62 = param_1[1];
  uStack_64 = *param_1;
  uStack_60 = *(undefined4 *)(param_1 + 6);
  uStack_5c = *(undefined4 *)(param_1 + 8);
  auStack_58[0] = *(undefined1 *)(param_1 + 10);
  uStack_54 = *(undefined4 *)(param_1 + 0xc);
  if (param_2 != (code *)0x0) {
    (*param_2)(0x47,&uStack_64);
    uVar2 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 0xe) = uVar2;
  }
  if (*(char *)(param_1 + 0xe) != '\0') {
    if (*(void **)(param_1 + 0x10) == (void *)0x0) {
      return;
    }
    free(*(void **)(param_1 + 0x10));
    return;
  }
  puVar3 = (undefined4 *)calloc(1,0x40);
  *(undefined4 **)(param_1 + 0x10) = puVar3;
  if (puVar3 == (undefined4 *)0x0) goto _L0;
  *(undefined1 *)((int)puVar3 + 10) = 1;
  *puVar3 = uStack_50;
  *(undefined1 *)((int)puVar3 + 9) = 0;
  puVar3[1] = uStack_4c;
  *(undefined1 *)(puVar3 + 2) = (undefined1)uStack_48;
  *(byte *)(puVar3 + 4) = bStack_43;
  puVar3[3] = (uint)bStack_44 << 0x18 | uStack_48 >> 8;
  puVar4 = (undefined4 *)calloc(1,0xc);
  if (puVar4 == (undefined4 *)0x0) goto _L0;
  *puVar4 = puVar3;
  if (bStack_43 == 4) {
_L0:
    array_copy_u48_to_u64(puVar3 + 6,auStack_42);
    uVar6 = uStack_3c & 0xff;
    *(undefined1 *)(puVar3 + 8) = (undefined1)uStack_3c;
    if ((uVar6 == 0) || (uVar1 = (uint)bStack_38 << 0x18 | uStack_3c >> 8, uVar1 == 0)) goto _L0;
    pvVar5 = calloc(uVar6,8);
    if (pvVar5 == (void *)0x0) goto _L0;
    array_copy_u48_to_u64(uVar1,uVar6);
    puVar3[9] = pvVar5;
_L0:
    puVar4[1] = pvVar5;
  }
  else {
    if (bStack_43 < 5) {
      if (bStack_43 == 2) {
        array_copy_u48_to_u64(puVar3 + 6,auStack_42);
        puVar3[0xb] = uStack_30;
        uVar6 = (uint)uStack_2c._1_1_;
        puVar3[8] = uStack_3c;
        puVar3[9] = CONCAT22(uStack_36,CONCAT11(bStack_37,bStack_38));
        puVar3[10] = CONCAT22(uStack_32,uStack_34);
        *(undefined2 *)(puVar3 + 0xc) = uStack_2c;
        if ((uVar6 != 0) && (iStack_2a != 0)) {
          pvVar5 = calloc(uVar6,8);
          if (pvVar5 == (void *)0x0) goto _L0;
          array_copy_u48_to_u64(iStack_2a,uVar6);
          puVar3[0xd] = pvVar5;
          puVar4[1] = pvVar5;
        }
      }
      else {
        if (bStack_43 != 3) {
          array_copy_u48_to_u64(auStack_42);
          uVar6 = (uint)uStack_2c._1_1_;
          puVar3[0xb] = uStack_30;
          puVar3[8] = uStack_3c;
          puVar3[9] = CONCAT22(uStack_36,CONCAT11(bStack_37,bStack_38));
          puVar3[10] = CONCAT22(uStack_32,uStack_34);
          *(undefined2 *)(puVar3 + 0xc) = uStack_2c;
          if ((uVar6 == 0) || (iStack_2a == 0)) goto _L0;
          pvVar5 = calloc(uVar6,8);
          if (pvVar5 == (void *)0x0) goto _L0;
          array_copy_u48_to_u64(iStack_2a,uVar6);
          puVar3[0xd] = pvVar5;
          goto _L0;
        }
        array_copy_u48_to_u64(auStack_42);
        puVar3[0xb] = uStack_30;
        uVar6 = (uint)uStack_2c._1_1_;
        puVar3[8] = uStack_3c;
        puVar3[9] = CONCAT22(uStack_36,CONCAT11(bStack_37,bStack_38));
        puVar3[10] = CONCAT22(uStack_32,uStack_34);
        *(undefined2 *)(puVar3 + 0xc) = uStack_2c;
        if ((uVar6 != 0) && (iStack_2a != 0)) {
          pvVar5 = calloc(uVar6,8);
          if (pvVar5 == (void *)0x0) goto _L0;
          array_copy_u48_to_u64(iStack_2a,uVar6);
          puVar3[0xd] = pvVar5;
          puVar4[1] = pvVar5;
        }
      }
      uVar6 = (uint)bStack_26;
      *(byte *)(puVar3 + 0xe) = bStack_26;
      if ((uVar6 == 0) || (uVar1 = iStack_24 << 8 | (uint)bStack_25, uVar1 == 0)) goto _L0;
      pvVar5 = calloc(uVar6,8);
      if (pvVar5 == (void *)0x0) {
_L0:
        esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
        return;
      }
      array_copy_u48_to_u64(uVar1,uVar6);
      puVar3[0xf] = pvVar5;
    }
    else {
      if (bStack_43 == 6) {
        array_copy_u48_to_u64(puVar3 + 6,auStack_42,1);
        uVar6 = uStack_3c & 0xff;
        *(undefined1 *)(puVar3 + 8) = (undefined1)uStack_3c;
        if ((uVar6 != 0) && (uVar1 = (uint)bStack_38 << 0x18 | uStack_3c >> 8, uVar1 != 0)) {
          pvVar5 = calloc(uVar6,8);
          if (pvVar5 == (void *)0x0) goto _L0;
          array_copy_u48_to_u64(uVar1,uVar6);
          puVar3[9] = pvVar5;
          puVar4[1] = pvVar5;
        }
      }
      else {
        if (bStack_43 != 7) {
          if (bStack_43 != 5) goto _L0;
          goto _L0;
        }
        array_copy_u48_to_u64(puVar3 + 6,auStack_42);
        uVar6 = uStack_3c & 0xff;
        *(undefined1 *)(puVar3 + 8) = (undefined1)uStack_3c;
        if ((uVar6 != 0) && (uVar1 = (uint)bStack_38 << 0x18 | uStack_3c >> 8, uVar1 != 0)) {
          pvVar5 = calloc(uVar6,8);
          if (pvVar5 == (void *)0x0) goto _L0;
          array_copy_u48_to_u64(uVar1,uVar6);
          puVar3[9] = pvVar5;
          puVar4[1] = pvVar5;
        }
      }
      uVar6 = (uint)bStack_37;
      *(byte *)(puVar3 + 10) = bStack_37;
      if ((uVar6 == 0) || (CONCAT22(uStack_34,uStack_36) == 0)) goto _L0;
      pvVar5 = calloc(uVar6,8);
      if (pvVar5 == (void *)0x0) goto _L0;
      array_copy_u48_to_u64(CONCAT22(uStack_34,uStack_36),uVar6);
      puVar3[0xb] = pvVar5;
    }
    puVar4[2] = pvVar5;
  }
_L0:
  *(code **)(param_1 + 0x12) = free_metering_snapshot_mem;
  *(undefined4 **)(param_1 + 0x14) = puVar4;
  return;
}

