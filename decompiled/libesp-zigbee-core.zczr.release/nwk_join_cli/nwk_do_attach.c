/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_cli.o -> nwk_do_attach
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_do_attach(nwk_join_req_t *req)

{
  nwk_rejoin_method_t nVar1;
  mac_cap_info_t mac_cap;
  char cVar2;
  nwk_potential_parent_t *pnVar3;
  nwk_potential_parent_t *parent;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  zmsg_t *msg;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  ezb_err_t eVar12;
  uint8_t uVar13;
  _Bool is_secur;
  uint uVar14;
  int iVar15;
  nwk_potential_parent_t *pnVar16;
  byte bVar17;
  undefined2 uStack_54;
  undefined2 uStack_52;
  ezb_panid_t panid;
  undefined1 auStack_4e [2];
  channel_page_t channel;
  undefined2 uStack_46;
  byte bStack_44;
  byte bStack_43;
  uint8_t uStack_42;
  
  uVar4 = nwk_address_get_panid_ref();
  if (uVar4 == 0xff) {
    return 0x2c3;
  }
  iVar5 = nwk_is_device_zed();
  nVar1 = req->rejoin_network;
  iVar6 = core_globals_get();
  uVar14 = 0;
  parent = (nwk_potential_parent_t *)0x0;
  do {
    uVar14 = bitmap_find_next_bit(iVar6 + 0xba4,6,uVar14);
    uVar14 = uVar14 & 0xff;
    if (5 < uVar14) {
      if (parent == (nwk_potential_parent_t *)0x0) {
        return 0x2c3;
      }
      nwk_address_get_panid(uVar4,&uStack_54);
      nwk_set_panid(uStack_54);
      iVar7 = core_globals_get();
      *(nwk_potential_parent_t **)(iVar7 + 0xac4) = parent;
      if (req->rejoin_network == '\0') {
        uVar14 = 3;
        if ((int)parent->field_7 << 0x13 < 0) goto _L0;
_L0:
        uVar14 = 0;
_L0:
        iVar7 = core_globals_get();
        *(char *)(iVar7 + 0xad3) = (char)uVar14;
        if (uVar14 == 3) {
          mac_cap = req->capability_info;
          is_secur = false;
          uVar13 = '\0';
          goto _L0;
        }
        if (uVar14 < 4) {
          if (uVar14 == 0) {
            _panid = CONCAT31(stack0xffffffb1,(((uint)parent->field_7 & 0x20000000) == 0) + '\x02');
            memcpy(auStack_4e,parent,8);
            uStack_46 = uStack_54;
            bStack_44 = (byte)((uint)parent->field_7 >> 7) & 0x1f;
            bStack_43 = SUB41(parent->field_7,0) & 0x7f;
            uStack_42 = req->capability_info;
            iVar5 = nwk_mm_asso_request(*(byte *)((int)&parent->field_7 + 3) & 0x1f,&panid);
            if (iVar5 != 0) {
              return iVar5;
            }
          }
          else {
            uVar13 = req->capability_info;
            bVar17 = req->field_0xa & 1;
            msg = (zmsg_t *)zmsg_alloc((-bVar17 & 0xe) + 0x21);
            if (msg == (zmsg_t *)0x0) {
              return 1;
            }
            zmsg_set_offset(0);
            uVar10 = nwk_get_short_address();
            nwk_frame_write_hdr(msg,uVar10,(parent->addr).short_addr,1,bVar17,0);
            iVar5 = core_globals_get();
            cVar2 = *(char *)(iVar5 + 0x9d9);
            *(char *)(iVar5 + 0x9d9) = cVar2 + '\x01';
            _panid = CONCAT31(stack0xffffffb1,cVar2);
            zmsg_write_bytes(msg,7,1,&panid);
            zmsg_append_u8(msg,'\x06');
            zmsg_append_u8(msg,uVar13);
            nwk_fwd_mac_data_req
                      (msg,*(byte *)((int)&parent->field_7 + 3) & 0x1f,(parent->addr).short_addr,0);
          }
          return 0;
        }
        uVar14 = uVar14 - 4 & 0xff;
        uVar13 = '\x01';
        if (uVar14 < 2) {
          mac_cap = req->capability_info;
          is_secur = (_Bool)(req->field_0xa & 1);
_L0:
          eVar12 = nwk_send_network_comm_req(parent,uVar13,is_secur,mac_cap);
          return eVar12;
        }
      }
      else if (req->rejoin_network == '\x02') {
        _panid = 0x5040201;
        uVar14 = (uint)(byte)auStack_4e
                             [((byte)req->field_0xa & 1) + ((uint)parent->field_7 >> 0xb & 2) + -2];
        if (uVar14 == 0) goto _L0;
_L0:
        uVar9 = nwk_get_short_address();
        if ((0xfff7 < uVar9) || (iVar7 = nwk_get_short_address(), iVar7 == 0)) {
          nwk_assign_shortaddr();
          nwk_set_short_address();
        }
        uVar10 = nwk_get_extended_address();
        uVar11 = nwk_get_short_address();
        uStack_52 = 0;
        iVar7 = nwk_address_update(uVar10,uVar11,&uStack_52);
        if (iVar7 == 0) {
          _panid = 1 << ((uint)parent->field_7 & 0x1f) & 0x7ffffffU |
                   ((uint)parent->field_7 >> 7) << 0x1b;
          iVar7 = nwk_mm_set_pib_attr(*(byte *)((int)&parent->field_7 + 3) & 0x1f,0x61,&panid);
          if (iVar7 == 0) {
            nwk_mm_set_pib_attr(*(byte *)((int)&parent->field_7 + 3) & 0x1f,0x4b,parent);
            goto _L0;
          }
        }
      }
      __assert_func(0,0,0,0);
    }
    iVar7 = uVar14 * 0x14;
    pnVar3 = parent;
    if (((*(byte *)(iVar6 + iVar7 + 0xb34) == uVar4) &&
        (bVar17 = *(byte *)(iVar6 + iVar7 + 0xb35), iVar8 = core_globals_get(),
        *(byte *)(iVar8 + 0xa37) <= bVar17)) &&
       (iVar8 = *(int *)(iVar6 + iVar7 + 0xb3c), iVar8 << 2 < 0)) {
      if (nVar1 == '\0') {
        if (iVar8 << 1 < 0) {
          iVar15 = iVar8 << 0x10;
          if (iVar5 == 0) {
            iVar15 = iVar8 << 0x11;
          }
          if (iVar15 < 0) goto _L0;
        }
      }
      else {
_L0:
        pnVar16 = (nwk_potential_parent_t *)(iVar7 + 0xb2c + iVar6);
        pnVar3 = pnVar16;
        if (parent != (nwk_potential_parent_t *)0x0) {
          if (((uint)pnVar16->update_id != (uint)parent->update_id) &&
             (pnVar3 = parent,
             (int)(((uint)parent->update_id - (uint)pnVar16->update_id) * 0x1000000) >> 0x18 < 0)) {
            pnVar3 = pnVar16;
          }
        }
      }
    }
    parent = pnVar3;
    uVar14 = uVar14 + 1 & 0xff;
  } while( true );
}

