/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_lqi_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_lqi_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  byte val;
  uint uVar1;
  undefined2 *puVar2;
  zmsg_t *pzVar3;
  uint8_t val_00;
  undefined1 uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  void *pvVar9;
  ezb_err_t eVar10;
  uint uVar11;
  uint __nmemb;
  byte bVar12;
  zdp_status_t zVar13;
  void *pvVar14;
  uint uVar15;
  byte abStack_4c [4];
  zdp_nwk_mgmt_lqi_req_field_t req;
  ezb_extaddr_t ext_addr;
  
  abStack_4c[0] = 0;
  if (((packet != (zdo_packet_t *)0x0) && (pzVar3 = packet->payload, pzVar3 != (zmsg_t *)0x0)) &&
     (resp != (zdo_packet_t *)0x0)) {
    _req = 0;
    uVar6 = zmsg_get_length(pzVar3);
    af_read_le8(pzVar3,(uint16_t *)&req,abStack_4c);
    if (_req <= uVar6) {
      val_00 = nwk_neighbor_table_get_size();
      puVar7 = (uint *)nwk_get_extended_panid();
      uVar6 = *puVar7;
      uVar15 = puVar7[1];
      if ((uVar15 + 1 != (uint)(uVar6 == 0)) || (uVar6 - 1 < 0xfffffffe)) {
        iVar8 = zdo_packet_max_available_space(0x8031);
        uVar1 = iVar8 - 4U & 0xff;
        __nmemb = uVar1 / 0x16;
        pvVar9 = calloc(__nmemb,0x16);
        if ((pvVar9 != (void *)0x0) || (uVar1 < 0x16)) {
          while( true ) {
            bVar12 = 0;
            iVar8 = 0;
            uVar1 = 0;
            while ((iVar8 = nwk_neighbor_table_next(iVar8), val = abStack_4c[0], iVar8 != 0 &&
                   (uVar1 < __nmemb))) {
              if (abStack_4c[0] <= bVar12) {
                nwk_neighbor_get_extaddr(&req);
                uVar5 = nwk_neighbor_get_shortaddr(iVar8);
                uVar4 = nwk_neighbor_get_lqa(iVar8);
                puVar2 = (undefined2 *)(uVar1 * 0x16 + (int)pvVar9);
                *puVar2 = (short)uVar6;
                puVar2[1] = (short)(uVar6 >> 0x10);
                puVar2[2] = (short)uVar15;
                puVar2[3] = (short)(uVar15 >> 0x10);
                memcpy(puVar2 + 4,&req,8);
                uVar11 = *(uint *)(iVar8 + 0xc);
                puVar2[8] = uVar5;
                uVar1 = uVar1 + 1 & 0xff;
                puVar2[9] = (ushort)(uVar11 >> 8) & 4 | (ushort)uVar11 & 3 |
                            (ushort)(uVar11 >> 2) & 0x70 | (ushort)(uVar11 >> 3) & 0x100 |
                            puVar2[9] & 0xfc80;
                uVar11 = *(uint *)(iVar8 + 0xc);
                *(undefined1 *)((int)puVar2 + 0x15) = uVar4;
                *(byte *)(puVar2 + 10) = (byte)(uVar11 >> 2) & 0xf;
              }
              bVar12 = bVar12 + 1;
            }
            pzVar3 = resp->payload;
            if (pzVar3 != (zmsg_t *)0x0) break;
            __assert_func(0,0,0,0);
            uVar6 = uVar6 >> 0x10;
            uVar15 = uVar15 >> 0x10;
          }
          eVar10 = zmsg_append_u8(pzVar3,'\0');
          if ((((eVar10 == 0) && (eVar10 = zmsg_append_u8(pzVar3,val_00), eVar10 == 0)) &&
              (eVar10 = zmsg_append_u8(pzVar3,val), eVar10 == 0)) &&
             (eVar10 = zmsg_append_u8(pzVar3,(uint8_t)uVar1), eVar10 == 0)) {
            if (pvVar9 == (void *)0x0) {
              return '\0';
            }
            if (uVar1 != 0) {
              uVar6 = 0;
              pvVar14 = pvVar9;
              do {
                uVar5 = *(undefined2 *)((int)pvVar14 + 0x12);
                iVar8 = zmsg_append_bytes(pzVar3,8,pvVar14);
                if ((iVar8 != 0) ||
                   (iVar8 = zmsg_append_bytes(pzVar3,8,(int)pvVar14 + 8), iVar8 != 0)) {
_L0:
                  zVar13 = 0x8a;
                  goto _L0;
                }
                _req = *(ushort *)((int)pvVar14 + 0x10);
                iVar8 = zmsg_append_bytes(pzVar3,2,&req);
                if ((((iVar8 != 0) ||
                     ((eVar10 = zmsg_append_u8(pzVar3,(byte)uVar5 & 0x7f), eVar10 != 0 ||
                      (eVar10 = zmsg_append_u8(pzVar3,(byte)((ushort)uVar5 >> 8) & 3), eVar10 != 0))
                     )) || (eVar10 = zmsg_append_u8(pzVar3,*(uint8_t *)((int)pvVar14 + 0x14)),
                           eVar10 != 0)) ||
                   (eVar10 = zmsg_append_u8(pzVar3,*(uint8_t *)((int)pvVar14 + 0x15)), eVar10 != 0))
                goto _L0;
                uVar6 = uVar6 + 1 & 0xff;
                pvVar14 = (void *)((int)pvVar14 + 0x16);
              } while (uVar1 != uVar6);
            }
            zVar13 = '\0';
          }
          else {
            zVar13 = 0x8a;
            if (pvVar9 == (void *)0x0) {
              return 0x8a;
            }
          }
_L0:
          mm_free(pvVar9);
          return zVar13;
        }
      }
    }
  }
  return 0xfe;
}

