/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_lqi_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_nwk_mgmt_lqi_req_handler(int param_1,int param_2)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  uint uVar9;
  uint *puVar10;
  void *pvVar11;
  int iVar12;
  uint uVar13;
  uint __nmemb;
  byte bVar14;
  undefined4 uVar15;
  void *pvVar16;
  uint uVar17;
  byte abStack_4c [4];
  ushort auStack_48 [10];
  
  abStack_4c[0] = 0;
  if (((param_1 != 0) && (iVar5 = *(int *)(param_1 + 0x14), iVar5 != 0)) && (param_2 != 0)) {
    auStack_48[0] = 0;
    uVar9 = zmsg_get_length(iVar5);
    af_read_le8_isra_0(iVar5,auStack_48,abStack_4c);
    if (auStack_48[0] <= uVar9) {
      uVar6 = nwk_neighbor_table_get_size();
      puVar10 = (uint *)nwk_get_extended_panid();
      uVar9 = *puVar10;
      uVar17 = puVar10[1];
      if ((uVar17 + 1 != (uint)(uVar9 == 0)) || (uVar9 - 1 < 0xfffffffe)) {
        iVar5 = zdo_packet_max_available_space(0x8031);
        uVar3 = iVar5 - 4U & 0xff;
        __nmemb = uVar3 / 0x16;
        pvVar11 = calloc(__nmemb,0x16);
        if ((pvVar11 != (void *)0x0) || (uVar3 < 0x16)) {
          while( true ) {
            bVar14 = 0;
            iVar5 = 0;
            uVar3 = 0;
            while ((iVar5 = nwk_neighbor_table_next(iVar5), bVar2 = abStack_4c[0], iVar5 != 0 &&
                   (uVar3 < __nmemb))) {
              if (abStack_4c[0] <= bVar14) {
                nwk_neighbor_get_extaddr(auStack_48);
                uVar8 = nwk_neighbor_get_shortaddr(iVar5);
                uVar7 = nwk_neighbor_get_lqa(iVar5);
                puVar4 = (undefined2 *)(uVar3 * 0x16 + (int)pvVar11);
                *puVar4 = (short)uVar9;
                puVar4[1] = (short)(uVar9 >> 0x10);
                puVar4[2] = (short)uVar17;
                puVar4[3] = (short)(uVar17 >> 0x10);
                memcpy(puVar4 + 4,auStack_48,8);
                uVar13 = *(uint *)(iVar5 + 0xc);
                puVar4[8] = uVar8;
                uVar3 = uVar3 + 1 & 0xff;
                puVar4[9] = (ushort)(uVar13 >> 8) & 4 | (ushort)uVar13 & 3 |
                            (ushort)(uVar13 >> 2) & 0x70 | (ushort)(uVar13 >> 3) & 0x100 |
                            puVar4[9] & 0xfc80;
                uVar13 = *(uint *)(iVar5 + 0xc);
                *(undefined1 *)((int)puVar4 + 0x15) = uVar7;
                *(byte *)(puVar4 + 10) = (byte)(uVar13 >> 2) & 0xf;
              }
              bVar14 = bVar14 + 1;
            }
            iVar5 = *(int *)(param_2 + 0x14);
            if (iVar5 != 0) break;
            __assert_func(0,0,0,0);
            uVar9 = uVar9 >> 0x10;
            uVar17 = uVar17 >> 0x10;
          }
          iVar12 = zmsg_append_u8(iVar5,0);
          if ((((iVar12 == 0) && (iVar12 = zmsg_append_u8(iVar5,uVar6), iVar12 == 0)) &&
              (iVar12 = zmsg_append_u8(iVar5,bVar2), iVar12 == 0)) &&
             (iVar12 = zmsg_append_u8(iVar5,uVar3), iVar12 == 0)) {
            if (pvVar11 == (void *)0x0) {
              return 0;
            }
            if (uVar3 != 0) {
              uVar9 = 0;
              pvVar16 = pvVar11;
              do {
                uVar1 = *(ushort *)((int)pvVar16 + 0x12);
                iVar12 = zmsg_append_bytes(iVar5,8,pvVar16);
                if ((iVar12 != 0) ||
                   (iVar12 = zmsg_append_bytes(iVar5,8,(int)pvVar16 + 8), iVar12 != 0)) {
_L0:
                  uVar15 = 0x8a;
                  goto _L0;
                }
                auStack_48[0] = *(ushort *)((int)pvVar16 + 0x10);
                iVar12 = zmsg_append_bytes(iVar5,2,auStack_48);
                if ((((iVar12 != 0) ||
                     ((iVar12 = zmsg_append_u8(iVar5,uVar1 & 0x7f), iVar12 != 0 ||
                      (iVar12 = zmsg_append_u8(iVar5,uVar1 >> 8 & 3), iVar12 != 0)))) ||
                    (iVar12 = zmsg_append_u8(iVar5,*(undefined1 *)((int)pvVar16 + 0x14)),
                    iVar12 != 0)) ||
                   (iVar12 = zmsg_append_u8(iVar5,*(undefined1 *)((int)pvVar16 + 0x15)), iVar12 != 0
                   )) goto _L0;
                uVar9 = uVar9 + 1 & 0xff;
                pvVar16 = (void *)((int)pvVar16 + 0x16);
              } while (uVar3 != uVar9);
            }
            uVar15 = 0;
          }
          else {
            uVar15 = 0x8a;
            if (pvVar11 == (void *)0x0) {
              return 0x8a;
            }
          }
_L0:
          mm_free(pvVar11);
          return uVar15;
        }
      }
    }
  }
  return 0xfe;
}

