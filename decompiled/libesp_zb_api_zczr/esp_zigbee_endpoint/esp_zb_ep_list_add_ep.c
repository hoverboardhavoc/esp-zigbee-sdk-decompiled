/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_endpoint.o -> esp_zb_ep_list_add_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ep_list_add_ep(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  byte *pbVar9;
  void *pvVar10;
  undefined2 *puVar11;
  short sVar12;
  byte bVar13;
  char cVar14;
  uint uVar15;
  char cVar16;
  undefined1 uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  size_t __nmemb;
  int iVar22;
  undefined1 uStack_55;
  undefined4 uStack_48;
  undefined2 *puStack_44;
  
  puVar7 = (undefined1 *)malloc(0x28);
  if (param_1 == 0) {
    uVar8 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ENDPOINT",&_LC1,uVar8,"ESP_ZIGBEE_ENDPOINT");
    uVar8 = 0x102;
  }
  else {
    uVar3 = (undefined1)((uint)param_3 >> 0x10);
    iVar19 = *(int *)(param_1 + 0x24);
    iVar6 = *(int *)(param_1 + 0x24);
    while (iVar22 = iVar19, iVar22 != 0) {
      iVar6 = iVar22;
      iVar19 = *(int *)(iVar22 + 0x24);
    }
    uStack_48 = 0;
    puStack_44 = (undefined2 *)0x0;
    if (param_2 == 0) {
      uStack_48 = 0;
      uVar20 = 0;
      __nmemb = 0;
      uVar21 = 0;
      puStack_44 = (undefined2 *)0x0;
    }
    else {
      bVar1 = false;
      bVar13 = 0;
      bVar2 = false;
      cVar14 = '\0';
      bVar4 = false;
      cVar16 = '\0';
      bVar5 = false;
      uVar20 = 0;
      iVar19 = param_2;
      while (iVar19 = *(int *)(iVar19 + 0x10), iVar19 != 0) {
        if (*(char *)(iVar19 + 8) == '\x01') {
          cVar14 = cVar14 + '\x01';
          bVar2 = true;
        }
        else {
          bVar13 = bVar13 + 1;
          bVar1 = true;
        }
        pbVar9 = (byte *)(*(int *)(iVar19 + 4) + 3);
        for (sVar12 = 0; sVar12 != *(short *)(iVar19 + 2); sVar12 = sVar12 + 1) {
          if ((*pbVar9 & 4) != 0) {
            cVar16 = cVar16 + '\x01';
            bVar4 = true;
          }
          pbVar9 = pbVar9 + 10;
        }
        uVar20 = uVar20 + 1 & 0xff;
        bVar5 = true;
      }
      if (bVar1) {
        uStack_48 = (uint)bVar13 << 0x18;
      }
      if (bVar2) {
        uStack_48 = (uint)CONCAT11(uStack_48._3_1_,cVar14) << 0x10;
      }
      if (bVar4) {
        uStack_48 = (uint)CONCAT21(uStack_48._2_2_,cVar16) << 8;
      }
      if (bVar5) {
        uStack_48 = CONCAT31(uStack_48._1_3_,(char)uVar20);
      }
      if (uVar20 != 0) {
        iVar19 = *(int *)(param_2 + 0x10);
        puStack_44 = (undefined2 *)calloc(uVar20,0xf);
        uVar21 = 0;
        if (puStack_44 == (undefined2 *)0x0) {
_L0:
          for (iVar19 = 0; iVar19 < (int)(uStack_48 & 0xff); iVar19 = iVar19 + 1) {
            if (*(int *)((int)puStack_44 + iVar19 * 0xf + 4) != 0) {
              for (iVar22 = 0; pvVar10 = *(void **)((int)puStack_44 + iVar19 * 0xf + 4),
                  iVar22 < (int)(uint)*(ushort *)((int)puStack_44 + iVar19 * 0xf + 2);
                  iVar22 = iVar22 + 1) {
                pvVar10 = *(void **)((int)pvVar10 + iVar22 * 10 + 6);
                if (pvVar10 != (void *)0x0) {
                  free(pvVar10);
                }
              }
              free(pvVar10);
            }
          }
          free(puStack_44);
          puStack_44 = (undefined2 *)0x0;
          uStack_48 = 0;
        }
        else {
          do {
            iVar22 = esp_zb_internal_zcl_clone_cluster
                               ((undefined1 *)(uVar21 * 0xf + (int)puStack_44),iVar19);
            if (iVar22 != 0) goto _L0;
            uVar21 = uVar21 + 1;
            iVar19 = *(int *)(iVar19 + 0x10);
          } while ((uVar21 & 0xff) < uVar20);
        }
      }
      uVar21 = uStack_48 & 0xff;
      __nmemb = uStack_48 >> 8 & 0xff;
      uVar20 = uStack_48 >> 0x10 & 0xff;
      uStack_48 = uStack_48 >> 0x18;
    }
    puVar7[0x12] = (char)((uint)puStack_44 >> 8);
    puVar7[0x13] = (char)((uint)puStack_44 >> 0x10);
    *puVar7 = (char)param_3;
    uVar17 = (undefined1)((uint)param_3 >> 8);
    puVar7[1] = uVar17;
    puVar7[2] = uVar3;
    puVar7[3] = 0;
    puVar7[4] = 0;
    puVar7[5] = 0;
    puVar7[6] = 0;
    puVar7[7] = 0;
    puVar7[8] = 0;
    puVar7[9] = 0;
    puVar7[10] = 0;
    puVar7[0xb] = 0;
    *(undefined4 *)(puVar7 + 0xc) = 0;
    puVar7[0x10] = (char)uVar21;
    puVar7[0x11] = (char)puStack_44;
    puVar7[0x14] = (char)((uint)puStack_44 >> 0x18);
    uStack_55 = (undefined1)((uint)param_3 >> 0x18);
    puVar11 = puStack_44;
    if (puStack_44 != (undefined2 *)0x0) {
      pvVar10 = malloc(0xc);
      puVar11 = (undefined2 *)realloc(pvVar10,(uVar20 + uStack_48 + 4) * 2);
      *(undefined1 *)((int)puVar11 + 3) = uStack_55;
      *(undefined1 *)((int)puVar11 + 1) = uVar17;
      *(char *)puVar11 = (char)param_3;
      *(undefined1 *)(puVar11 + 1) = uVar3;
      *(char *)(puVar11 + 2) = (char)param_4;
      *(byte *)((int)puVar11 + 5) = (byte)((uint)param_4 >> 8) & 0xf;
      *(char *)(puVar11 + 3) = (char)uVar20;
      *(char *)((int)puVar11 + 7) = (char)uStack_48;
      uVar15 = 0;
      for (uVar18 = 0; uVar18 != uVar21; uVar18 = uVar18 + 1 & 0xff) {
        if (*(char *)(puStack_44 + 4) == '\x01') {
          puVar11[uVar15 + 4] = *puStack_44;
          uVar15 = uVar15 + 1 & 0xff;
        }
        else if (*(char *)(puStack_44 + 4) == '\x02') {
          puVar11[uVar20 + 4] = *puStack_44;
          uVar20 = uVar20 + 1 & 0xff;
        }
        puStack_44 = (undefined2 *)((int)puStack_44 + 0xf);
      }
    }
    puVar7[0x15] = (char)puVar11;
    puVar7[0x16] = (char)((uint)puVar11 >> 8);
    puVar7[0x17] = (char)((uint)puVar11 >> 0x10);
    puVar7[0x18] = (char)((uint)puVar11 >> 0x18);
    puVar7[0x1a] = (char)__nmemb;
    pvVar10 = (void *)0x0;
    if (__nmemb != 0) {
      pvVar10 = calloc(__nmemb,0x38);
    }
    puVar7[0x1c] = (char)((uint)pvVar10 >> 8);
    puVar7[0x1d] = (char)((uint)pvVar10 >> 0x10);
    puVar7[0x1e] = (char)((uint)pvVar10 >> 0x18);
    puVar7[0x1b] = (char)pvVar10;
    puVar7[0x1f] = 1;
    pvVar10 = calloc(1,7);
    *(void **)(puVar7 + 0x20) = pvVar10;
    *(undefined4 *)(puVar7 + 0x24) = 0;
    if (iVar6 == 0) {
      *(undefined1 **)(param_1 + 0x24) = puVar7;
    }
    else {
      *(undefined1 **)(iVar6 + 0x24) = puVar7;
    }
    uVar8 = 0;
  }
  return uVar8;
}

