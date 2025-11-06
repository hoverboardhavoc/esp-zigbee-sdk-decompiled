/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> data_model_adapter.o -> esp_zb_internal_ep_list_to_device_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * esp_zb_internal_ep_list_to_device_ctx(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  uint uVar3;
  undefined1 *__ptr;
  void *__ptr_00;
  void *__dest;
  undefined2 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  void *pvVar7;
  int iVar8;
  undefined1 *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  void *pvVar13;
  uint __nmemb;
  size_t __nmemb_00;
  size_t __nmemb_01;
  uint uVar14;
  void *pvVar15;
  uint uVar16;
  undefined2 uVar17;
  undefined1 *puVar18;
  int iVar19;
  void *local_70;
  int iStack_6c;
  void *pvStack_68;
  void *pvStack_64;
  byte bStack_50;
  byte bStack_4f;
  byte bStack_4e;
  byte bStack_4d;
  undefined2 *puStack_4c;
  uint uStack_48;
  void *pvStack_44;
  
  if (param_1 == 0) {
    return (undefined1 *)0x0;
  }
  pvVar13 = *(void **)(param_1 + 0x24);
  __nmemb_01 = 0;
  local_70 = pvVar13;
_L0:
  if (pvVar13 == (void *)0x0) {
    __ptr = (undefined1 *)malloc(5);
    if (__ptr == (undefined1 *)0x0) {
      return (undefined1 *)0x0;
    }
    *__ptr = (char)__nmemb_01;
    if (__nmemb_01 == 0) {
      __ptr[1] = 0;
      __ptr[2] = 0;
      __ptr[3] = 0;
      __ptr[4] = 0;
_L0:
      esp_zb_internal_ep_list_free(param_1);
      return __ptr;
    }
    __ptr_00 = calloc(__nmemb_01,4);
    __ptr[2] = (char)((uint)__ptr_00 >> 8);
    __ptr[3] = (char)((uint)__ptr_00 >> 0x10);
    __ptr[1] = (char)__ptr_00;
    __ptr[4] = (char)((uint)__ptr_00 >> 0x18);
    if (__ptr_00 == (void *)0x0) {
_L0:
      free(__ptr);
      return (undefined1 *)0x0;
    }
    iStack_6c = 0;
    do {
      __dest = malloc(0x24);
      *(void **)(iStack_6c * 4 + (int)__ptr_00) = __dest;
      if (__dest == (void *)0x0) {
        for (iVar19 = 0; iVar19 < (int)__nmemb_01; iVar19 = iVar19 + 1) {
          pvVar13 = *(void **)(iVar19 * 4 + (int)__ptr_00);
          if (pvVar13 != (void *)0x0) {
            uStack_48 = (uint)*(byte *)((int)pvVar13 + 0x10);
            pvStack_44 = *(void **)((int)pvVar13 + 0x11);
            esp_zb_cluster_array_cleanup(&uStack_48);
            if (*(void **)((int)pvVar13 + 0x1b) != (void *)0x0) {
              free(*(void **)((int)pvVar13 + 0x1b));
            }
            if (*(void **)((int)pvVar13 + 0x20) != (void *)0x0) {
              free(*(void **)((int)pvVar13 + 0x20));
            }
            free(pvVar13);
          }
        }
        free(__ptr_00);
        goto _L0;
      }
      memcpy(__dest,local_70,0x24);
      pvVar13 = (void *)((uint)*(byte *)((int)__dest + 0x14) << 0x18);
      uVar16 = (uint)pvVar13 | *(uint *)((int)__dest + 0x10) >> 8;
      if (uVar16 == 0) {
        uVar14 = 0;
        uVar3 = 0;
        __nmemb_00 = 0;
        __nmemb = 0;
        puVar4 = (undefined2 *)0x0;
      }
      else {
        uVar14 = 0;
        uVar3 = 0;
        __nmemb_00 = 0;
        __nmemb = 0;
        pvStack_64 = *(void **)(uVar16 + 0x10);
        for (pvVar15 = pvStack_64; pvVar15 != (void *)0x0; pvVar15 = *(void **)((int)pvVar15 + 0x10)
            ) {
          if (*(char *)((int)pvVar15 + 8) == '\x01') {
            uVar3 = uVar3 + 1 & 0xff;
          }
          else {
            uVar14 = uVar14 + 1 & 0xff;
          }
          for (iVar19 = *(int *)((int)pvVar15 + 4); iVar19 != 0; iVar19 = *(int *)(iVar19 + 0xc)) {
            if ((*(byte *)(iVar19 + 3) & 4) != 0) {
              __nmemb_00 = __nmemb_00 + 1 & 0xff;
            }
          }
          __nmemb = __nmemb + 1 & 0xff;
        }
        puVar4 = (undefined2 *)0x0;
        if (__nmemb != 0) {
          puVar4 = (undefined2 *)calloc(__nmemb,0xf);
          pvStack_68 = (void *)0x0;
          if (puVar4 == (undefined2 *)0x0) {
            bStack_50 = (byte)__nmemb;
            bStack_4f = (byte)__nmemb_00;
            bStack_4e = (byte)uVar3;
            bStack_4d = (byte)uVar14;
            puStack_4c = (undefined2 *)0x0;
            esp_zb_cluster_array_cleanup(&bStack_50);
            __nmemb = (uint)bStack_50;
            __nmemb_00 = (size_t)bStack_4f;
            uVar3 = (uint)bStack_4e;
            uVar14 = (uint)bStack_4d;
            puVar4 = puStack_4c;
          }
          else {
            do {
              pvVar15 = (void *)((int)puVar4 + (int)pvStack_68 * 0xf);
              memcpy(pvVar15,pvStack_64,0xf);
              iVar19 = *(int *)((int)pvVar15 + 4);
              uVar16 = 0;
              iVar8 = iVar19;
              if (iVar19 == 0) {
                uVar5 = esp_log_timestamp();
                esp_log(1,"ESP_ZIGBEE_DM_ADAPTER",
                        "E (%lu) %s: Uninitialized attribute linked list!\n",uVar5,
                        "ESP_ZIGBEE_DM_ADAPTER");
                uVar17 = 0;
                pvVar7 = (void *)0x0;
              }
              else {
                do {
                  iVar11 = iVar8;
                  uVar10 = uVar16;
                  uVar16 = uVar10 + 1;
                  iVar8 = *(int *)(iVar11 + 0xc);
                } while (*(int *)(iVar11 + 0xc) != 0);
                uVar17 = (undefined2)uVar10;
                pvVar7 = (void *)0x0;
                if ((uVar10 & 0xffff) != 0) {
                  puVar6 = (undefined4 *)malloc(0x10);
                  uVar17 = *(undefined2 *)(iVar11 + 10);
                  *puVar6 = 0xffff;
                  puVar6[1] = 0xffff;
                  *(undefined2 *)((int)puVar6 + 10) = uVar17;
                  *(undefined2 *)(puVar6 + 2) = 0;
                  puVar6[3] = 0;
                  *(undefined4 **)(iVar11 + 0xc) = puVar6;
                  uVar12 = (uVar10 & 0xffff) + 1;
                  iVar19 = *(int *)(iVar19 + 0xc);
                  pvVar7 = calloc(uVar10 + 1 & 0xffff,10);
                  uVar17 = (undefined2)uVar12;
                  uVar16 = 0;
                  if (pvVar7 == (void *)0x0) {
_L0:
                    uStack_48 = CONCAT22(uStack_48._2_2_,(short)(uVar12 * 0x10000 >> 0x10));
                    pvStack_44 = pvVar7;
                    esp_zb_attr_array_cleanup(&uStack_48);
                    uVar17 = (undefined2)uStack_48;
                    pvVar7 = pvStack_44;
                  }
                  else {
                    while ((uVar16 & 0xffff) < (uVar12 & 0xffff)) {
                      iVar8 = esp_zb_internal_zcl_attr_clone
                                        ((void *)(uVar16 * 10 + (int)pvVar7),iVar19);
                      uVar16 = uVar16 + 1;
                      if (iVar8 != 0) goto _L0;
                      iVar19 = *(int *)(iVar19 + 0xc);
                    }
                  }
                }
              }
              pvStack_64 = *(void **)((int)pvStack_64 + 0x10);
              *(char *)((int)pvVar15 + 3) = (char)((ushort)uVar17 >> 8);
              *(char *)((int)pvVar15 + 4) = (char)pvVar7;
              *(char *)((int)pvVar15 + 5) = (char)((uint)pvVar7 >> 8);
              pvVar13 = (void *)((int)pvStack_68 + 1);
              *(char *)((int)pvVar15 + 6) = (char)((uint)pvVar7 >> 0x10);
              *(char *)((int)pvVar15 + 7) = (char)((uint)pvVar7 >> 0x18);
              *(char *)((int)pvVar15 + 2) = (char)uVar17;
              pvStack_68 = pvVar13;
            } while (((uint)pvVar13 & 0xff) < __nmemb);
          }
        }
      }
      puVar18 = *(undefined1 **)((int)__dest + 0xc);
      *(undefined4 *)((int)__dest + 0xc) = 0;
      if (puVar18 == (undefined1 *)0x0) goto _L0;
      *(char *)((int)__dest + 0x12) = (char)((uint)puVar4 >> 8);
      *(char *)((int)__dest + 0x13) = (char)((uint)puVar4 >> 0x10);
      *(char *)((int)__dest + 0x10) = (char)__nmemb;
      *(char *)((int)__dest + 0x11) = (char)puVar4;
      *(char *)((int)__dest + 0x14) = (char)((uint)puVar4 >> 0x18);
      if ((puVar4 == (undefined2 *)0x0) ||
         (puVar9 = (undefined1 *)malloc((uVar3 + uVar14 + 4) * 2), puVar9 == (undefined1 *)0x0)) {
        puVar9 = (undefined1 *)0x0;
      }
      else {
        *puVar9 = *puVar18;
        uVar1 = puVar18[2];
        puVar9[1] = puVar18[1];
        puVar9[2] = uVar1;
        uVar1 = puVar18[3];
        puVar9[4] = puVar18[4];
        bVar2 = puVar18[5];
        puVar9[3] = uVar1;
        puVar9[6] = (char)uVar3;
        puVar9[5] = bVar2 & 0xf;
        puVar9[7] = (char)uVar14;
        uVar16 = 0;
        for (uVar14 = 0; __nmemb != uVar14; uVar14 = uVar14 + 1 & 0xff) {
          if (*(char *)(puVar4 + 4) == '\x01') {
            *(undefined2 *)(puVar9 + uVar16 * 2 + 8) = *puVar4;
            uVar16 = uVar16 + 1 & 0xff;
          }
          else if (*(char *)(puVar4 + 4) == '\x02') {
            *(undefined2 *)(puVar9 + uVar3 * 2 + 8) = *puVar4;
            uVar3 = uVar3 + 1 & 0xff;
          }
          puVar4 = (undefined2 *)((int)puVar4 + 0xf);
        }
      }
      *(char *)((int)__dest + 0x15) = (char)puVar9;
      *(char *)((int)__dest + 0x16) = (char)((uint)puVar9 >> 8);
      *(char *)((int)__dest + 0x18) = (char)((uint)puVar9 >> 0x18);
      *(char *)((int)__dest + 0x17) = (char)((uint)puVar9 >> 0x10);
      *(char *)((int)__dest + 0x1a) = (char)__nmemb_00;
      pvVar13 = (void *)0x0;
      if (__nmemb_00 != 0) {
        pvVar13 = calloc(__nmemb_00,0x38);
      }
      *(char *)((int)__dest + 0x1b) = (char)pvVar13;
      *(char *)((int)__dest + 0x1c) = (char)((uint)pvVar13 >> 8);
      *(char *)((int)__dest + 0x1e) = (char)((uint)pvVar13 >> 0x18);
      *(char *)((int)__dest + 0x1d) = (char)((uint)pvVar13 >> 0x10);
      *(undefined1 *)((int)__dest + 0x1f) = 1;
      pvVar13 = calloc(1,7);
      *(void **)((int)__dest + 0x20) = pvVar13;
      local_70 = *(void **)((int)local_70 + 0x24);
      iStack_6c = iStack_6c + 1;
      if ((int)__nmemb_01 <= iStack_6c) goto _L0;
    } while( true );
  }
  goto _L0;
_L0:
  zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/utility/data_model_adapter.c"
            ,0xed);
_L0:
  pvVar13 = *(void **)((int)pvVar13 + 0x24);
  __nmemb_01 = __nmemb_01 + 1 & 0xff;
  goto _L0;
}

