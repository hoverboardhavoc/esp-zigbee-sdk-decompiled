/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> data_model_adapter.o -> esp_zb_internal_ep_list_to_device_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint * esp_zb_internal_ep_list_to_device_ctx(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  size_t __nmemb;
  uint *__ptr;
  void *__dest;
  undefined2 *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  void *pvVar11;
  undefined2 *puVar12;
  uint uVar13;
  char cVar14;
  char cVar15;
  undefined2 uVar16;
  short sVar17;
  char cVar18;
  uint uVar19;
  uint uVar20;
  undefined1 *puVar21;
  int iVar22;
  void *pvVar23;
  void *__src;
  size_t __nmemb_00;
  void *__src_00;
  uint uVar24;
  int iVar25;
  void *pvStack_5c;
  undefined4 uStack_50;
  undefined2 *puStack_4c;
  uint uStack_48;
  void *pvStack_44;
  
  if (param_1 == 0) {
    return (uint *)0x0;
  }
  pvVar23 = *(void **)(param_1 + 0x24);
  __nmemb = 0;
  __src = pvVar23;
_L0:
  if (pvVar23 == (void *)0x0) {
    __ptr = (uint *)malloc(5);
    if (__ptr == (uint *)0x0) {
      return (uint *)0x0;
    }
    *(byte *)__ptr = (byte)__nmemb;
    if (__nmemb == 0) {
      *(byte *)((int)__ptr + 1) = 0;
      *(byte *)((int)__ptr + 2) = 0;
      *(byte *)((int)__ptr + 3) = 0;
      *(byte *)(__ptr + 1) = 0;
_L0:
      esp_zb_internal_ep_list_free(param_1);
      return __ptr;
    }
    pvVar23 = calloc(__nmemb,4);
    *(byte *)((int)__ptr + 2) = (byte)((uint)pvVar23 >> 8);
    *(byte *)((int)__ptr + 3) = (byte)((uint)pvVar23 >> 0x10);
    *(byte *)((int)__ptr + 1) = (byte)pvVar23;
    *(byte *)(__ptr + 1) = (byte)((uint)pvVar23 >> 0x18);
    iVar22 = 0;
    if (pvVar23 == (void *)0x0) {
_L0:
      free(__ptr);
      return (uint *)0x0;
    }
    pvVar23 = (void *)0xffff;
    pvStack_5c = (void *)0xffff;
    do {
      __dest = malloc(0x24);
      uVar19 = (uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8;
      *(void **)(iVar22 * 4 + uVar19) = __dest;
      if (__dest == (void *)0x0) {
        iVar22 = 0;
        if (uVar19 != 0) {
          for (; pvVar23 = (void *)((uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8),
              iVar22 < (int)(uint)(byte)*__ptr; iVar22 = iVar22 + 1) {
            iVar10 = iVar22 * 4;
            iVar25 = *(int *)((int)pvVar23 + iVar10);
            if (iVar25 != 0) {
              uStack_48 = (uint)*(byte *)(iVar25 + 0x10);
              pvStack_44 = *(void **)(iVar25 + 0x11);
              esp_zb_cluster_array_cleanup(&uStack_48);
              pvVar23 = *(void **)(*(int *)(((uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8) + iVar10) +
                                  0x1b);
              if (pvVar23 != (void *)0x0) {
                free(pvVar23);
              }
              pvVar23 = *(void **)(*(int *)(((uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8) + iVar10) +
                                  0x20);
              if (pvVar23 != (void *)0x0) {
                free(pvVar23);
              }
              free(*(void **)(((uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8) + iVar10));
            }
          }
          free(pvVar23);
        }
        goto _L0;
      }
      memcpy(__dest,__src,0x24);
      uStack_50 = 0;
      uVar19 = (uint)*(byte *)((int)__dest + 0x14) << 0x18 | *(uint *)((int)__dest + 0x10) >> 8;
      puStack_4c = (undefined2 *)0x0;
      if (uVar19 == 0) {
        uVar19 = 0;
        uVar20 = 0;
        __nmemb_00 = 0;
        uVar24 = 0;
      }
      else {
        bVar3 = false;
        bVar4 = false;
        cVar14 = '\0';
        bVar5 = false;
        cVar15 = '\0';
        bVar6 = false;
        cVar18 = '\0';
        uVar20 = 0;
        __src_00 = *(void **)(uVar19 + 0x10);
        for (pvVar11 = __src_00; pvVar11 != (void *)0x0; pvVar11 = *(void **)((int)pvVar11 + 0x10))
        {
          if (*(char *)((int)pvVar11 + 8) == '\x01') {
            cVar15 = cVar15 + '\x01';
            bVar5 = true;
          }
          else {
            cVar14 = cVar14 + '\x01';
            bVar4 = true;
          }
          for (iVar25 = *(int *)((int)pvVar11 + 4); iVar25 != 0; iVar25 = *(int *)(iVar25 + 0xc)) {
            if ((*(byte *)(iVar25 + 3) & 4) != 0) {
              cVar18 = cVar18 + '\x01';
              bVar6 = true;
            }
          }
          uVar20 = uVar20 + 1 & 0xff;
          bVar3 = true;
        }
        if (bVar3) {
          uStack_50 = uVar20;
        }
        if (bVar4) {
          uStack_50 = CONCAT13(cVar14,(undefined3)uStack_50);
        }
        if (bVar5) {
          uStack_50._0_3_ = CONCAT12(cVar15,(undefined2)uStack_50);
        }
        if (bVar6) {
          uStack_50._0_2_ = CONCAT11(cVar18,(undefined1)uStack_50);
        }
        if (uVar20 != 0) {
          puVar7 = (undefined2 *)calloc(uVar20,0xf);
          uVar19 = 0;
          puStack_4c = puVar7;
          if (puVar7 == (undefined2 *)0x0) {
            esp_zb_cluster_array_cleanup(&uStack_50);
          }
          else {
            do {
              pvVar23 = (void *)0xf;
              puVar21 = (undefined1 *)((int)puVar7 + uVar19 * 0xf);
              memcpy(puVar21,__src_00,0xf);
              uVar24 = uStack_48;
              iVar25 = *(int *)(puVar21 + 4);
              uStack_48 = uStack_48 & 0xffff0000;
              pvStack_44 = (void *)0x0;
              if (iVar25 == 0) {
                uVar8 = esp_log_timestamp();
                esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_LC1,uVar8,"ESP_ZIGBEE_DM_ADAPTER");
                uVar16 = 0;
                pvVar11 = (void *)0x0;
              }
              else {
                bVar3 = false;
                iVar10 = iVar25;
                sVar17 = 0;
                while( true ) {
                  if (*(int *)(iVar10 + 0xc) == 0) break;
                  bVar3 = true;
                  iVar10 = *(int *)(iVar10 + 0xc);
                  sVar17 = sVar17 + 1;
                }
                if (bVar3) {
                  uStack_48._2_2_ = SUB42(uVar24,2);
                  uStack_48 = CONCAT22(uStack_48._2_2_,sVar17);
                }
                uVar24 = uStack_48 & 0xffff;
                if (uVar24 != 0) {
                  puVar9 = (undefined4 *)malloc(0x10);
                  uVar24 = uVar24 + 1;
                  uVar16 = *(undefined2 *)(iVar10 + 10);
                  *puVar9 = 0xffff;
                  *(undefined2 *)((int)puVar9 + 10) = uVar16;
                  puVar9[1] = 0xffff;
                  *(undefined2 *)(puVar9 + 2) = 0;
                  puVar9[3] = 0;
                  uVar13 = uVar24 & 0xffff;
                  *(undefined4 **)(iVar10 + 0xc) = puVar9;
                  iVar25 = *(int *)(iVar25 + 0xc);
                  uStack_48 = CONCAT22(uStack_48._2_2_,(short)(uVar24 * 0x10000 >> 0x10));
                  pvVar23 = pvStack_5c;
                  pvVar11 = calloc(uVar13,10);
                  uVar24 = 0;
                  pvStack_44 = pvVar11;
                  if (pvVar11 == (void *)0x0) {
_L0:
                    esp_zb_attr_array_cleanup(&uStack_48);
                  }
                  else {
                    while ((uVar24 & 0xffff) < uVar13) {
                      pvVar23 = (void *)0xa;
                      iVar10 = esp_zb_internal_zcl_attr_clone
                                         ((void *)(uVar24 * 10 + (int)pvVar11),iVar25);
                      uVar24 = uVar24 + 1;
                      if (iVar10 != 0) goto _L0;
                      iVar25 = *(int *)(iVar25 + 0xc);
                    }
                  }
                }
                uVar16 = (undefined2)uStack_48;
                pvVar11 = pvStack_44;
              }
              puVar21[5] = (char)((uint)pvVar11 >> 8);
              puVar21[6] = (char)((uint)pvVar11 >> 0x10);
              puVar21[2] = (char)uVar16;
              uVar19 = uVar19 + 1;
              puVar21[7] = (char)((uint)pvVar11 >> 0x18);
              puVar21[4] = (char)pvVar11;
              puVar21[3] = (char)((ushort)uVar16 >> 8);
              __src_00 = *(void **)((int)__src_00 + 0x10);
            } while ((uVar19 & 0xff) < uVar20);
          }
        }
        uVar24 = uStack_50 & 0xff;
        __nmemb_00 = uStack_50 >> 8 & 0xff;
        uVar20 = uStack_50 >> 0x10 & 0xff;
        uVar19 = uStack_50 >> 0x18;
      }
      puVar7 = puStack_4c;
      puVar21 = *(undefined1 **)((int)__dest + 0xc);
      *(undefined4 *)((int)__dest + 0xc) = 0;
      if (puVar21 == (undefined1 *)0x0) goto _L0;
      *(char *)((int)__dest + 0x12) = (char)((uint)puStack_4c >> 8);
      *(char *)((int)__dest + 0x13) = (char)((uint)puStack_4c >> 0x10);
      *(char *)((int)__dest + 0x10) = (char)uVar24;
      *(char *)((int)__dest + 0x11) = (char)puStack_4c;
      *(char *)((int)__dest + 0x14) = (char)((uint)puStack_4c >> 0x18);
      puVar12 = puStack_4c;
      if (puStack_4c != (undefined2 *)0x0) {
        pvVar11 = malloc(0xc);
        puVar12 = (undefined2 *)realloc(pvVar11,(uVar20 + uVar19 + 4) * 2);
        uVar13 = 0;
        *(undefined1 *)puVar12 = *puVar21;
        uVar1 = puVar21[2];
        *(undefined1 *)((int)puVar12 + 1) = puVar21[1];
        *(undefined1 *)(puVar12 + 1) = uVar1;
        uVar1 = puVar21[3];
        *(undefined1 *)(puVar12 + 2) = puVar21[4];
        bVar2 = puVar21[5];
        *(undefined1 *)((int)puVar12 + 3) = uVar1;
        *(char *)(puVar12 + 3) = (char)uVar20;
        *(byte *)((int)puVar12 + 5) = bVar2 & 0xf;
        *(char *)((int)puVar12 + 7) = (char)uVar19;
        for (uVar19 = 0; uVar24 != uVar19; uVar19 = uVar19 + 1 & 0xff) {
          if (*(char *)(puVar7 + 4) == '\x01') {
            puVar12[uVar13 + 4] = *puVar7;
            uVar13 = uVar13 + 1 & 0xff;
          }
          else if (*(char *)(puVar7 + 4) == '\x02') {
            puVar12[uVar20 + 4] = *puVar7;
            uVar20 = uVar20 + 1 & 0xff;
          }
          puVar7 = (undefined2 *)((int)puVar7 + 0xf);
        }
      }
      *(char *)((int)__dest + 0x15) = (char)puVar12;
      *(char *)((int)__dest + 0x16) = (char)((uint)puVar12 >> 8);
      *(char *)((int)__dest + 0x17) = (char)((uint)puVar12 >> 0x10);
      *(char *)((int)__dest + 0x18) = (char)((uint)puVar12 >> 0x18);
      *(char *)((int)__dest + 0x1a) = (char)__nmemb_00;
      pvVar11 = (void *)0x0;
      if (__nmemb_00 != 0) {
        pvVar11 = calloc(__nmemb_00,0x38);
      }
      *(char *)((int)__dest + 0x1c) = (char)((uint)pvVar11 >> 8);
      *(char *)((int)__dest + 0x1b) = (char)pvVar11;
      *(char *)((int)__dest + 0x1d) = (char)((uint)pvVar11 >> 0x10);
      *(char *)((int)__dest + 0x1e) = (char)((uint)pvVar11 >> 0x18);
      *(undefined1 *)((int)__dest + 0x1f) = 1;
      pvVar11 = calloc(1,7);
      *(void **)((int)__dest + 0x20) = pvVar11;
      iVar22 = iVar22 + 1;
      __src = *(void **)((int)__src + 0x24);
      if ((int)__nmemb <= iVar22) goto _L0;
    } while( true );
  }
  goto _L0;
_L0:
  zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/utility/data_model_adapter.c"
            ,0xeb);
_L0:
  pvVar23 = *(void **)((int)pvVar23 + 0x24);
  __nmemb = __nmemb + 1 & 0xff;
  goto _L0;
}

