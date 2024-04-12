/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_ias_zone_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_zone_cluster_add_attr(int param_1,uint param_2,undefined2 *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  ushort *puVar12;
  ushort *puVar13;
  undefined2 *__ptr;
  undefined1 *puVar14;
  undefined4 uVar15;
  undefined2 *puVar16;
  
  __ptr = (undefined2 *)malloc(0x10);
  if (param_1 == 0) {
    uVar15 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar15,0x10000);
    return 0x102;
  }
  puVar12 = *(ushort **)(param_1 + 0xc);
  if ((*(ushort **)(param_1 + 0xc))[5] != 0x500) {
    uVar15 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC11,uVar15,0x10000);
    return 0x102;
  }
  do {
    puVar13 = puVar12;
    if (puVar13 == (ushort *)0x0) break;
    if (*puVar13 == param_2) {
      uVar15 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC7,uVar15,0x10000,param_2);
      return 0x102;
    }
    puVar12 = *(ushort **)(puVar13 + 6);
  } while (*(ushort **)(puVar13 + 6) != (ushort *)0x0);
  *__ptr = (short)param_2;
  if (param_2 == 0x12) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x20;
    puVar14 = (undefined1 *)malloc(1);
    *puVar14 = *(undefined1 *)param_3;
    __ptr[3] = (short)puVar14;
    __ptr[4] = (short)((uint)puVar14 >> 0x10);
  }
  else if (param_2 < 0x13) {
    if (param_2 == 2) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x19;
      puVar16 = (undefined2 *)malloc(2);
      *puVar16 = *param_3;
      __ptr[3] = (short)puVar16;
      __ptr[4] = (short)((uint)puVar16 >> 0x10);
    }
    else if (param_2 < 3) {
      if (param_2 == 0) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x30;
        puVar14 = (undefined1 *)malloc(1);
        *puVar14 = *(undefined1 *)param_3;
        __ptr[3] = (short)puVar14;
        __ptr[4] = (short)((uint)puVar14 >> 0x10);
      }
      else {
        if (param_2 != 1) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x31;
        puVar16 = (undefined2 *)malloc(2);
        *puVar16 = *param_3;
        __ptr[3] = (short)puVar16;
        __ptr[4] = (short)((uint)puVar16 >> 0x10);
      }
    }
    else if (param_2 == 0x10) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0xf0;
      puVar14 = (undefined1 *)malloc(8);
      uVar1 = *(undefined1 *)((int)param_3 + 1);
      uVar2 = *(undefined1 *)(param_3 + 1);
      uVar3 = *(undefined1 *)((int)param_3 + 3);
      uVar4 = *(undefined1 *)(param_3 + 2);
      uVar5 = *(undefined1 *)((int)param_3 + 5);
      uVar6 = *(undefined1 *)(param_3 + 3);
      uVar7 = *(undefined1 *)((int)param_3 + 7);
      *puVar14 = *(undefined1 *)param_3;
      puVar14[1] = uVar1;
      puVar14[2] = uVar2;
      puVar14[3] = uVar3;
      puVar14[4] = uVar4;
      puVar14[5] = uVar5;
      puVar14[6] = uVar6;
      puVar14[7] = uVar7;
      __ptr[3] = (short)puVar14;
      __ptr[4] = (short)((uint)puVar14 >> 0x10);
    }
    else {
      if (param_2 != 0x11) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x20;
      puVar14 = (undefined1 *)malloc(1);
      *puVar14 = *(undefined1 *)param_3;
      __ptr[3] = (short)puVar14;
      __ptr[4] = (short)((uint)puVar14 >> 0x10);
    }
  }
  else if (param_2 == 0xe001) {
    *(undefined1 *)((int)__ptr + 3) = 0x40;
    *(undefined1 *)(__ptr + 1) = 1;
    puVar14 = (undefined1 *)malloc(1);
    *puVar14 = *(undefined1 *)param_3;
    __ptr[3] = (short)puVar14;
    __ptr[4] = (short)((uint)puVar14 >> 0x10);
  }
  else if (param_2 < 0xe002) {
    if (param_2 == 0x13) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x20;
      puVar14 = (undefined1 *)malloc(1);
      *puVar14 = *(undefined1 *)param_3;
      __ptr[3] = (short)puVar14;
      __ptr[4] = (short)((uint)puVar14 >> 0x10);
    }
    else {
      if (param_2 != 0xe000) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 0x40;
      *(undefined1 *)(__ptr + 1) = 1;
      puVar14 = (undefined1 *)malloc(1);
      *puVar14 = *(undefined1 *)param_3;
      __ptr[3] = (short)puVar14;
      __ptr[4] = (short)((uint)puVar14 >> 0x10);
    }
  }
  else if (param_2 == 0xe002) {
    *(undefined1 *)((int)__ptr + 3) = 0x40;
    *(undefined1 *)(__ptr + 1) = 2;
    puVar16 = (undefined2 *)malloc(2);
    *puVar16 = *param_3;
    __ptr[3] = (short)puVar16;
    __ptr[4] = (short)((uint)puVar16 >> 0x10);
  }
  else {
    if (param_2 != 0xeffe) {
_L0:
      uVar15 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_L0,uVar15,0x10000);
      free(__ptr);
      return 0x102;
    }
    *(undefined1 *)((int)__ptr + 3) = 0x40;
    *(undefined1 *)(__ptr + 1) = 0;
    if (param_3 == (undefined2 *)0x0) {
      uVar15 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC12,uVar15,0x10000);
      free(__ptr);
      return 0x102;
    }
    *(undefined1 *)(__ptr + 1) = 0xc;
    puVar14 = (undefined1 *)malloc(0xc);
    uVar1 = *(undefined1 *)((int)param_3 + 1);
    uVar2 = *(undefined1 *)(param_3 + 1);
    uVar3 = *(undefined1 *)((int)param_3 + 3);
    uVar4 = *(undefined1 *)(param_3 + 2);
    uVar5 = *(undefined1 *)((int)param_3 + 5);
    uVar6 = *(undefined1 *)(param_3 + 3);
    uVar7 = *(undefined1 *)((int)param_3 + 7);
    uVar8 = *(undefined1 *)(param_3 + 4);
    uVar9 = *(undefined1 *)((int)param_3 + 9);
    uVar10 = *(undefined1 *)(param_3 + 5);
    uVar11 = *(undefined1 *)((int)param_3 + 0xb);
    *puVar14 = *(undefined1 *)param_3;
    puVar14[1] = uVar1;
    puVar14[2] = uVar2;
    puVar14[3] = uVar3;
    puVar14[4] = uVar4;
    puVar14[5] = uVar5;
    puVar14[6] = uVar6;
    puVar14[7] = uVar7;
    puVar14[8] = uVar8;
    puVar14[9] = uVar9;
    puVar14[10] = uVar10;
    puVar14[0xb] = uVar11;
    __ptr[3] = (short)puVar14;
    __ptr[4] = (short)((uint)puVar14 >> 0x10);
  }
  __ptr[2] = 0xffff;
  __ptr[5] = 0x500;
  *(undefined4 *)(__ptr + 6) = 0;
  if (puVar13 == (ushort *)0x0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(puVar13 + 6) = __ptr;
  }
  return 0;
}

