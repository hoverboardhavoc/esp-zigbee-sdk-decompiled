/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_ota_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ota_cluster_add_attr(ushort *param_1,uint param_2,undefined4 *param_3)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar3;
  undefined2 *__ptr;
  ushort *puVar4;
  size_t __size;
  undefined4 uVar5;
  undefined4 *puVar6;
  void *pvVar7;
  int extraout_a1;
  size_t sVar8;
  ushort uVar9;
  ushort *puVar10;
  ushort uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  
  if (param_2 < 0xd) {
    if (param_2 == 0) {
      uVar9 = 1;
      sVar8 = 0xf0;
      goto _L0;
    }
    uVar13 = 1 << (param_2 & 0x1f);
    if ((uVar13 & 0x3a8) == 0) {
      if ((uVar13 & 0x416) == 0) {
        sVar8 = 0x30;
        uVar9 = 1;
        if ((uVar13 & 0x1840) == 0) goto _L0;
      }
      else {
        uVar9 = 1;
        sVar8 = 0x23;
      }
      goto _L0;
    }
  }
  else if (param_2 != 0xfff2) {
    if (0xfff2 < param_2) {
      if (param_2 == 0xfff3) {
        uVar9 = 1;
        sVar8 = 0x20;
        goto _L0;
      }
_L0:
      uVar5 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC6,uVar5,0x10000);
      return 0x102;
    }
    if (param_2 == 0xfff0) {
      if (param_3 == (undefined4 *)0x0) {
        uVar5 = 0x62d;
_L407:
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                  ,uVar5);
      }
      puVar6 = (undefined4 *)malloc(0x10);
      bVar1 = *(byte *)(param_3 + 2);
      pvVar7 = malloc((uint)bVar1 << 3);
      *puVar6 = param_3;
      puVar6[1] = param_3 + 1;
      *(byte *)(puVar6 + 2) = bVar1;
      puVar6[3] = pvVar7;
    }
    else {
      if (param_2 != 0xfff1) goto _L0;
      uVar5 = 0x616;
      if (param_3 == (undefined4 *)0x0) goto _L407;
      puVar6 = (undefined4 *)malloc(0x10);
      uVar3 = *(undefined2 *)param_3;
      *puVar6 = 0;
      *(undefined1 *)((int)puVar6 + 0xb) = 0;
      *(undefined2 *)(puVar6 + 1) = uVar3;
      *(undefined2 *)((int)puVar6 + 6) = 1;
      uVar3 = *(undefined2 *)((int)param_3 + 2);
      *(undefined1 *)(puVar6 + 3) = 0;
      *(undefined2 *)(puVar6 + 2) = uVar3;
      *(undefined1 *)((int)puVar6 + 10) = *(undefined1 *)(param_3 + 1);
    }
    uVar9 = 0x40;
    sVar8 = 0x10;
    param_3 = puVar6;
    goto _L0;
  }
  uVar9 = 1;
  sVar8 = 0x21;
_L0:
  if (param_1 == (ushort *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar5,0x10000);
    return 0x102;
  }
  sVar2 = *(short *)(*(int *)(param_1 + 6) + 10);
  puVar4 = param_1;
  if (sVar2 == 0x19) goto _L0;
  uVar5 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC2,uVar5,0x10000,sVar2);
_L0:
  iVar14 = 0x102;
  puVar4 = param_1;
  do {
    __ptr = (undefined2 *)malloc(0x10);
    if (__ptr == (undefined2 *)0x0) {
      return 0x102;
    }
    uVar11 = uVar9 & 0x40;
    if (uVar11 == 0) {
      __size = esp_zb_zcl_get_attribute_size(sVar8,param_3);
      if (__size == 0xffff) goto _L0;
_L0:
      pvVar7 = (void *)0x0;
      if (__size != 0) {
        pvVar7 = malloc(__size);
        if (pvVar7 == (void *)0x0) goto _L0;
        memcpy(pvVar7,param_3,__size);
      }
      __ptr[2] = 0xffff;
      iVar12 = *(int *)(param_1 + 6);
      *(char *)((int)__ptr + 3) = (char)uVar9;
      *(char *)(__ptr + 1) = (char)sVar8;
      uVar3 = *(undefined2 *)(iVar12 + 10);
      __ptr[3] = (short)pvVar7;
      *__ptr = (short)param_2;
      __ptr[4] = (short)((uint)pvVar7 >> 0x10);
      __ptr[5] = uVar3;
      *(undefined4 *)(__ptr + 6) = 0;
      *(undefined2 **)(puVar4 + 6) = __ptr;
      if (iVar14 == 0) {
        return 0;
      }
_L0:
      free(__ptr);
      return 0x102;
    }
    __size = sVar8;
    if (param_3 != (undefined4 *)0x0) goto _L0;
    puVar4 = (ushort *)
             zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                       ,0x6b);
    if ((extraout_a1 == 0x8000) && (-1 < (short)uVar11)) break;
_L0:
    while (puVar10 = *(ushort **)(puVar4 + 6), puVar10 != (ushort *)0x0) {
      puVar4 = puVar10;
      if (*puVar10 == param_2) {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC4,uVar5,0x10000,param_2);
        return 0x102;
      }
    }
    iVar14 = 0;
  } while( true );
  uVar5 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC3,uVar5,0x10000);
  goto _L0;
}

