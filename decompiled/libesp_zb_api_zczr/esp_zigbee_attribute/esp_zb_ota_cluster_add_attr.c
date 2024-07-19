/*
 * Last changed at upstream commit 280ac146dc8285567eab4df113b3f6356493fe0b
 * https://github.com/espressif/esp-zigbee-sdk/commit/280ac146dc8285567eab4df113b3f6356493fe0b
 * Upstream date: 2024-07-19 11:49:15 +0800
 * Upstream subject: esp-zigbee-lib:(94bd7a1a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_ota_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ota_cluster_add_attr(ushort *param_1,uint param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined1 uVar2;
  short sVar3;
  undefined2 uVar4;
  undefined2 *__ptr;
  ushort *puVar5;
  size_t __size;
  undefined4 uVar6;
  undefined4 *puVar7;
  void *pvVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  int extraout_a1;
  size_t sVar11;
  ushort uVar12;
  ushort *puVar13;
  ushort uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  
  if (param_2 < 0xd) {
    if (param_2 == 0) {
      uVar12 = 1;
      sVar11 = 0xf0;
      goto _L0;
    }
    uVar16 = 1 << (param_2 & 0x1f);
    if ((uVar16 & 0x3a8) == 0) {
      if ((uVar16 & 0x416) == 0) {
        sVar11 = 0x30;
        uVar12 = 1;
        if ((uVar16 & 0x1840) == 0) goto _L0;
      }
      else {
        uVar12 = 1;
        sVar11 = 0x23;
      }
      goto _L0;
    }
  }
  else if (param_2 != 0xfff2) {
    if (0xfff2 < param_2) {
      if (param_2 == 0xfff3) {
        uVar12 = 1;
        sVar11 = 0x20;
        goto _L0;
      }
_L0:
      uVar6 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC6,uVar6,0x10000);
      return 0x102;
    }
    if (param_2 == 0xfff0) {
      if (param_3 == (undefined4 *)0x0) {
        uVar6 = 0x62d;
_L407:
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                  ,uVar6);
      }
      puVar7 = (undefined4 *)malloc(0x10);
      bVar1 = *(byte *)(param_3 + 2);
      pvVar8 = malloc((uint)bVar1 << 3);
      puVar9 = (undefined1 *)malloc(1);
      uVar2 = *(undefined1 *)param_3;
      *puVar7 = puVar9;
      *puVar9 = uVar2;
      puVar10 = (undefined4 *)malloc(4);
      uVar6 = param_3[1];
      puVar7[1] = puVar10;
      *(byte *)(puVar7 + 2) = bVar1;
      *puVar10 = uVar6;
      puVar7[3] = pvVar8;
    }
    else {
      if (param_2 != 0xfff1) goto _L0;
      uVar6 = 0x616;
      if (param_3 == (undefined4 *)0x0) goto _L407;
      puVar7 = (undefined4 *)malloc(0x10);
      uVar4 = *(undefined2 *)param_3;
      *puVar7 = 0;
      *(undefined1 *)((int)puVar7 + 0xb) = 0;
      *(undefined2 *)(puVar7 + 1) = uVar4;
      *(undefined2 *)((int)puVar7 + 6) = uVar4;
      uVar4 = *(undefined2 *)((int)param_3 + 2);
      *(undefined1 *)(puVar7 + 3) = 0;
      *(undefined2 *)(puVar7 + 2) = uVar4;
      *(undefined1 *)((int)puVar7 + 10) = *(undefined1 *)(param_3 + 1);
    }
    uVar12 = 0x40;
    sVar11 = 0x10;
    param_3 = puVar7;
    goto _L0;
  }
  uVar12 = 1;
  sVar11 = 0x21;
_L0:
  if (param_1 == (ushort *)0x0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar6,0x10000);
    return 0x102;
  }
  sVar3 = *(short *)(*(int *)(param_1 + 6) + 10);
  puVar5 = param_1;
  if (sVar3 == 0x19) goto _L0;
  uVar6 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC2,uVar6,0x10000,sVar3);
_L0:
  iVar17 = 0x102;
  puVar5 = param_1;
  do {
    __ptr = (undefined2 *)malloc(0x10);
    if (__ptr == (undefined2 *)0x0) {
      return 0x102;
    }
    uVar14 = uVar12 & 0x40;
    if (uVar14 == 0) {
      __size = esp_zb_zcl_get_attribute_size(sVar11,param_3);
      if (__size == 0xffff) goto _L0;
_L0:
      pvVar8 = (void *)0x0;
      if (__size != 0) {
        pvVar8 = malloc(__size);
        if (pvVar8 == (void *)0x0) goto _L0;
        memcpy(pvVar8,param_3,__size);
      }
      __ptr[2] = 0xffff;
      iVar15 = *(int *)(param_1 + 6);
      *(char *)((int)__ptr + 3) = (char)uVar12;
      *(char *)(__ptr + 1) = (char)sVar11;
      uVar4 = *(undefined2 *)(iVar15 + 10);
      __ptr[3] = (short)pvVar8;
      *__ptr = (short)param_2;
      __ptr[4] = (short)((uint)pvVar8 >> 0x10);
      __ptr[5] = uVar4;
      *(undefined4 *)(__ptr + 6) = 0;
      *(undefined2 **)(puVar5 + 6) = __ptr;
      if (iVar17 == 0) {
        return 0;
      }
_L0:
      free(__ptr);
      return 0x102;
    }
    __size = sVar11;
    if (param_3 != (undefined4 *)0x0) goto _L0;
    puVar5 = (ushort *)
             zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                       ,0x6b);
    if ((extraout_a1 == 0x8000) && (-1 < (short)uVar14)) break;
_L0:
    while (puVar13 = *(ushort **)(puVar5 + 6), puVar13 != (ushort *)0x0) {
      puVar5 = puVar13;
      if (*puVar13 == param_2) {
        uVar6 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC4,uVar6,0x10000,param_2);
        return 0x102;
      }
    }
    iVar17 = 0;
  } while( true );
  uVar6 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC3,uVar6,0x10000);
  goto _L0;
}

