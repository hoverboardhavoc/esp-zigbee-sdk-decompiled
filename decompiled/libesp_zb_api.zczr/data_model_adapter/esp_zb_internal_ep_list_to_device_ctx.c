/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> data_model_adapter.o -> esp_zb_internal_ep_list_to_device_ctx
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
  void *pvVar10;
  int iVar11;
  undefined1 *puVar12;
  void *pvVar13;
  uint uVar14;
  char cVar15;
  char cVar16;
  undefined2 uVar17;
  short sVar18;
  char cVar19;
  uint uVar20;
  uint uVar21;
  undefined1 *puVar22;
  int iVar23;
  void *pvVar24;
  void *__src;
  size_t __nmemb_00;
  void *__src_00;
  uint uVar25;
  int iVar26;
  void *pvStack_5c;
  undefined4 uStack_50;
  undefined2 *puStack_4c;
  uint uStack_48;
  void *pvStack_44;
  
  if (param_1 == 0) {
    return (uint *)0x0;
  }
  pvVar24 = *(void **)(param_1 + 0x24);
  __nmemb = 0;
  __src = pvVar24;
_L0:
  if (pvVar24 == (void *)0x0) {
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
    pvVar24 = calloc(__nmemb,4);
    *(byte *)((int)__ptr + 2) = (byte)((uint)pvVar24 >> 8);
    *(byte *)((int)__ptr + 3) = (byte)((uint)pvVar24 >> 0x10);
    *(byte *)((int)__ptr + 1) = (byte)pvVar24;
    *(byte *)(__ptr + 1) = (byte)((uint)pvVar24 >> 0x18);
    iVar23 = 0;
    if (pvVar24 == (void *)0x0) {
_L0:
      free(__ptr);
      return (uint *)0x0;
    }
    pvVar24 = (void *)0xffff;
    pvStack_5c = (void *)0xffff;
    do {
      __dest = malloc(0x24);
      uVar20 = (uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8;
      *(void **)(iVar23 * 4 + uVar20) = __dest;
      if (__dest == (void *)0x0) {
        iVar23 = 0;
        if (uVar20 != 0) {
          for (; pvVar24 = (void *)((uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8),
              iVar23 < (int)(uint)(byte)*__ptr; iVar23 = iVar23 + 1) {
            iVar11 = iVar23 * 4;
            iVar26 = *(int *)((int)pvVar24 + iVar11);
            if (iVar26 != 0) {
              uStack_48 = (uint)*(byte *)(iVar26 + 0x10);
              pvStack_44 = *(void **)(iVar26 + 0x11);
              esp_zb_cluster_array_cleanup(&uStack_48);
              pvVar24 = *(void **)(*(int *)(((uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8) + iVar11) +
                                  0x1b);
              if (pvVar24 != (void *)0x0) {
                free(pvVar24);
              }
              pvVar24 = *(void **)(*(int *)(((uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8) + iVar11) +
                                  0x20);
              if (pvVar24 != (void *)0x0) {
                free(pvVar24);
              }
              free(*(void **)(((uint)(byte)__ptr[1] << 0x18 | *__ptr >> 8) + iVar11));
            }
          }
          free(pvVar24);
        }
        goto _L0;
      }
      memcpy(__dest,__src,0x24);
      uStack_50 = 0;
      uVar20 = (uint)*(byte *)((int)__dest + 0x14) << 0x18 | *(uint *)((int)__dest + 0x10) >> 8;
      puStack_4c = (undefined2 *)0x0;
      if (uVar20 == 0) {
        uVar20 = 0;
        uVar21 = 0;
        __nmemb_00 = 0;
        uVar25 = 0;
      }
      else {
        bVar3 = false;
        bVar4 = false;
        cVar15 = '\0';
        bVar5 = false;
        cVar16 = '\0';
        bVar6 = false;
        cVar19 = '\0';
        uVar21 = 0;
        __src_00 = *(void **)(uVar20 + 0x10);
        for (pvVar13 = __src_00; pvVar13 != (void *)0x0; pvVar13 = *(void **)((int)pvVar13 + 0x10))
        {
          if (*(char *)((int)pvVar13 + 8) == '\x01') {
            cVar16 = cVar16 + '\x01';
            bVar5 = true;
          }
          else {
            cVar15 = cVar15 + '\x01';
            bVar4 = true;
          }
          for (iVar26 = *(int *)((int)pvVar13 + 4); iVar26 != 0; iVar26 = *(int *)(iVar26 + 0xc)) {
            if ((*(byte *)(iVar26 + 3) & 4) != 0) {
              cVar19 = cVar19 + '\x01';
              bVar6 = true;
            }
          }
          uVar21 = uVar21 + 1 & 0xff;
          bVar3 = true;
        }
        if (bVar3) {
          uStack_50 = uVar21;
        }
        if (bVar4) {
          uStack_50 = CONCAT13(cVar15,(undefined3)uStack_50);
        }
        if (bVar5) {
          uStack_50._0_3_ = CONCAT12(cVar16,(undefined2)uStack_50);
        }
        if (bVar6) {
          uStack_50._0_2_ = CONCAT11(cVar19,(undefined1)uStack_50);
        }
        if (uVar21 != 0) {
          puVar7 = (undefined2 *)calloc(uVar21,0xf);
          uVar20 = 0;
          puStack_4c = puVar7;
          if (puVar7 == (undefined2 *)0x0) {
            esp_zb_cluster_array_cleanup(&uStack_50);
          }
          else {
            do {
              pvVar24 = (void *)0xf;
              pvVar13 = (void *)((int)puVar7 + uVar20 * 0xf);
              memcpy(pvVar13,__src_00,0xf);
              uVar25 = uStack_48;
              iVar26 = *(int *)((int)pvVar13 + 4);
              uStack_48 = uStack_48 & 0xffff0000;
              pvStack_44 = (void *)0x0;
              if (iVar26 == 0) {
                uVar8 = esp_log_timestamp();
                esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_LC1,uVar8,"ESP_ZIGBEE_DM_ADAPTER");
                uVar17 = 0;
                pvVar10 = (void *)0x0;
              }
              else {
                bVar3 = false;
                iVar11 = iVar26;
                sVar18 = 0;
                while( true ) {
                  if (*(int *)(iVar11 + 0xc) == 0) break;
                  bVar3 = true;
                  iVar11 = *(int *)(iVar11 + 0xc);
                  sVar18 = sVar18 + 1;
                }
                if (bVar3) {
                  uStack_48._2_2_ = SUB42(uVar25,2);
                  uStack_48 = CONCAT22(uStack_48._2_2_,sVar18);
                }
                uVar25 = uStack_48 & 0xffff;
                if (uVar25 != 0) {
                  puVar9 = (undefined4 *)malloc(0x10);
                  uVar25 = uVar25 + 1;
                  uVar17 = *(undefined2 *)(iVar11 + 10);
                  *puVar9 = 0xffff;
                  *(undefined2 *)((int)puVar9 + 10) = uVar17;
                  puVar9[1] = 0xffff;
                  *(undefined2 *)(puVar9 + 2) = 0;
                  puVar9[3] = 0;
                  uVar14 = uVar25 & 0xffff;
                  *(undefined4 **)(iVar11 + 0xc) = puVar9;
                  iVar26 = *(int *)(iVar26 + 0xc);
                  uStack_48 = CONCAT22(uStack_48._2_2_,(short)(uVar25 * 0x10000 >> 0x10));
                  pvVar24 = pvStack_5c;
                  pvVar10 = calloc(uVar14,10);
                  uVar25 = 0;
                  pvStack_44 = pvVar10;
                  if (pvVar10 == (void *)0x0) {
_L0:
                    esp_zb_attr_array_cleanup(&uStack_48);
                  }
                  else {
                    while ((uVar25 & 0xffff) < uVar14) {
                      pvVar24 = (void *)0xa;
                      iVar11 = esp_zb_internal_zcl_attr_clone
                                         ((void *)(uVar25 * 10 + (int)pvVar10),iVar26);
                      uVar25 = uVar25 + 1;
                      if (iVar11 != 0) goto _L0;
                      iVar26 = *(int *)(iVar26 + 0xc);
                    }
                  }
                }
                uVar17 = (undefined2)uStack_48;
                pvVar10 = pvStack_44;
              }
              *(char *)((int)pvVar13 + 5) = (char)((uint)pvVar10 >> 8);
              *(char *)((int)pvVar13 + 6) = (char)((uint)pvVar10 >> 0x10);
              *(char *)((int)pvVar13 + 2) = (char)uVar17;
              uVar20 = uVar20 + 1;
              *(char *)((int)pvVar13 + 7) = (char)((uint)pvVar10 >> 0x18);
              *(char *)((int)pvVar13 + 4) = (char)pvVar10;
              *(char *)((int)pvVar13 + 3) = (char)((ushort)uVar17 >> 8);
              __src_00 = *(void **)((int)__src_00 + 0x10);
            } while ((uVar20 & 0xff) < uVar21);
          }
        }
        uVar25 = uStack_50 & 0xff;
        __nmemb_00 = uStack_50 >> 8 & 0xff;
        uVar21 = uStack_50 >> 0x10 & 0xff;
        uVar20 = uStack_50 >> 0x18;
      }
      puVar7 = puStack_4c;
      puVar22 = *(undefined1 **)((int)__dest + 0xc);
      *(undefined4 *)((int)__dest + 0xc) = 0;
      if (puVar22 == (undefined1 *)0x0) goto _L0;
      *(char *)((int)__dest + 0x12) = (char)((uint)puStack_4c >> 8);
      *(char *)((int)__dest + 0x13) = (char)((uint)puStack_4c >> 0x10);
      *(char *)((int)__dest + 0x10) = (char)uVar25;
      *(char *)((int)__dest + 0x11) = (char)puStack_4c;
      *(char *)((int)__dest + 0x14) = (char)((uint)puStack_4c >> 0x18);
      if ((puStack_4c == (undefined2 *)0x0) ||
         (puVar12 = (undefined1 *)malloc((uVar21 + uVar20 + 4) * 2), puVar12 == (undefined1 *)0x0))
      {
        puVar12 = (undefined1 *)0x0;
      }
      else {
        uVar14 = 0;
        *puVar12 = *puVar22;
        uVar1 = puVar22[2];
        puVar12[1] = puVar22[1];
        puVar12[2] = uVar1;
        uVar1 = puVar22[3];
        puVar12[4] = puVar22[4];
        bVar2 = puVar22[5];
        puVar12[3] = uVar1;
        puVar12[6] = (char)uVar21;
        puVar12[5] = bVar2 & 0xf;
        puVar12[7] = (char)uVar20;
        for (uVar20 = 0; uVar25 != uVar20; uVar20 = uVar20 + 1 & 0xff) {
          if (*(char *)(puVar7 + 4) == '\x01') {
            *(undefined2 *)(puVar12 + uVar14 * 2 + 8) = *puVar7;
            uVar14 = uVar14 + 1 & 0xff;
          }
          else if (*(char *)(puVar7 + 4) == '\x02') {
            *(undefined2 *)(puVar12 + uVar21 * 2 + 8) = *puVar7;
            uVar21 = uVar21 + 1 & 0xff;
          }
          puVar7 = (undefined2 *)((int)puVar7 + 0xf);
        }
      }
      *(char *)((int)__dest + 0x15) = (char)puVar12;
      *(char *)((int)__dest + 0x16) = (char)((uint)puVar12 >> 8);
      *(char *)((int)__dest + 0x18) = (char)((uint)puVar12 >> 0x18);
      *(char *)((int)__dest + 0x17) = (char)((uint)puVar12 >> 0x10);
      *(char *)((int)__dest + 0x1a) = (char)__nmemb_00;
      pvVar13 = (void *)0x0;
      if (__nmemb_00 != 0) {
        pvVar13 = calloc(__nmemb_00,0x38);
      }
      *(char *)((int)__dest + 0x1c) = (char)((uint)pvVar13 >> 8);
      *(char *)((int)__dest + 0x1b) = (char)pvVar13;
      *(char *)((int)__dest + 0x1d) = (char)((uint)pvVar13 >> 0x10);
      *(char *)((int)__dest + 0x1e) = (char)((uint)pvVar13 >> 0x18);
      *(undefined1 *)((int)__dest + 0x1f) = 1;
      pvVar13 = calloc(1,7);
      *(void **)((int)__dest + 0x20) = pvVar13;
      iVar23 = iVar23 + 1;
      __src = *(void **)((int)__src + 0x24);
      if ((int)__nmemb <= iVar23) goto _L0;
    } while( true );
  }
  goto _L0;
_L0:
  zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/utility/data_model_adapter.c"
            ,0xed);
_L0:
  pvVar24 = *(void **)((int)pvVar24 + 0x24);
  __nmemb = __nmemb + 1 & 0xff;
  goto _L0;
}

