/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  nwk_potential_parent_t *parent;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  zmsg_t *msg;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  ezb_err_t eVar11;
  uint8_t uVar12;
  _Bool is_secur;
  uint uVar13;
  int iVar14;
  nwk_potential_parent_t *pnVar15;
  byte bVar16;
  undefined2 uStack_54;
  undefined2 uStack_52;
  ezb_panid_t panid;
  undefined1 auStack_4e [2];
  channel_page_t channel;
  undefined2 uStack_46;
  byte bStack_44;
  byte bStack_43;
  uint8_t uStack_42;
  
  uVar3 = nwk_address_get_panid_ref();
  if (uVar3 == 0xff) {
    return 0x2c3;
  }
  iVar4 = nwk_is_device_zed();
  nVar1 = req->rejoin_network;
  iVar5 = core_globals_get();
  uVar13 = 0;
  parent = (nwk_potential_parent_t *)0x0;
  do {
    uVar13 = bitmap_find_next_bit(iVar5 + 0xba4,6,uVar13);
    uVar13 = uVar13 & 0xff;
    if (5 < uVar13) {
      if (parent == (nwk_potential_parent_t *)0x0) {
        return 0x2c3;
      }
      nwk_address_get_panid(uVar3,&uStack_54);
      nwk_set_panid(uStack_54);
      iVar6 = core_globals_get();
      *(nwk_potential_parent_t **)(iVar6 + 0xac4) = parent;
      if (req->rejoin_network == '\0') {
        uVar13 = 3;
        if ((int)parent->field_7 << 0x13 < 0) goto _L0;
_L0:
        uVar13 = 0;
_L0:
        iVar6 = core_globals_get();
        *(char *)(iVar6 + 0xad3) = (char)uVar13;
        if (uVar13 == 3) {
          mac_cap = req->capability_info;
          is_secur = false;
          uVar12 = '\0';
          goto _L0;
        }
        if (uVar13 < 4) {
          if (uVar13 == 0) {
            _panid = CONCAT31(stack0xffffffb1,(((uint)parent->field_7 & 0x20000000) == 0) + '\x02');
            memcpy(auStack_4e,parent,8);
            uStack_46 = uStack_54;
            bStack_44 = (byte)((uint)parent->field_7 >> 7) & 0x1f;
            bStack_43 = SUB41(parent->field_7,0) & 0x7f;
            uStack_42 = req->capability_info;
            nwk_mm_asso_request(*(byte *)((int)&parent->field_7 + 3) & 0x1f,&panid);
          }
          else {
            uVar12 = req->capability_info;
            bVar16 = req->field_0xa & 1;
            msg = (zmsg_t *)zmsg_alloc((-bVar16 & 0xe) + 0x21);
            if (msg == (zmsg_t *)0x0) {
              return 1;
            }
            zmsg_set_offset(0);
            uVar9 = nwk_get_short_address();
            nwk_frame_write_hdr(msg,uVar9,(parent->addr).short_addr,1,bVar16,0);
            iVar4 = core_globals_get();
            cVar2 = *(char *)(iVar4 + 0x9d9);
            *(char *)(iVar4 + 0x9d9) = cVar2 + '\x01';
            _panid = CONCAT31(stack0xffffffb1,cVar2);
            zmsg_write_bytes(msg,7,1,&panid);
            zmsg_append_u8(msg,'\x06');
            zmsg_append_u8(msg,uVar12);
            nwk_fwd_mac_data_req
                      (msg,*(byte *)((int)&parent->field_7 + 3) & 0x1f,(parent->addr).short_addr,0);
          }
          return 0;
        }
        uVar13 = uVar13 - 4 & 0xff;
        uVar12 = '\x01';
        if (uVar13 < 2) {
          mac_cap = req->capability_info;
          is_secur = (_Bool)(req->field_0xa & 1);
_L0:
          eVar11 = nwk_send_network_comm_req(parent,uVar12,is_secur,mac_cap);
          return eVar11;
        }
      }
      else if (req->rejoin_network == '\x02') {
        _panid = 0x5040201;
        uVar13 = (uint)(byte)auStack_4e
                             [((byte)req->field_0xa & 1) + ((uint)parent->field_7 >> 0xb & 2) + -2];
        if (uVar13 == 0) goto _L0;
_L0:
        uVar8 = nwk_get_short_address();
        if ((0xfff7 < uVar8) || (iVar6 = nwk_get_short_address(), iVar6 == 0)) {
          nwk_assign_shortaddr();
          nwk_set_short_address();
        }
        uVar9 = nwk_get_extended_address();
        uVar10 = nwk_get_short_address();
        uStack_52 = 0;
        iVar6 = nwk_address_update(uVar9,uVar10,&uStack_52);
        if (iVar6 == 0) {
          _panid = 1 << ((uint)parent->field_7 & 0x1f) & 0x7ffffffU |
                   ((uint)parent->field_7 >> 7) << 0x1b;
          iVar6 = nwk_mm_set_pib_attr(0xff,0x61,&panid);
          if (iVar6 == 0) {
            nwk_mm_set_pib_attr(0xff,0x4b,parent);
            goto _L0;
          }
        }
      }
      __assert_func(0,0,0,0);
    }
    iVar6 = uVar13 * 0x14;
    if (((*(byte *)(iVar5 + iVar6 + 0xb34) == uVar3) &&
        (bVar16 = *(byte *)(iVar5 + iVar6 + 0xb35), iVar7 = core_globals_get(),
        *(byte *)(iVar7 + 0xa37) <= bVar16)) &&
       (iVar7 = *(int *)(iVar5 + iVar6 + 0xb3c), iVar7 << 2 < 0)) {
      if (nVar1 == '\0') {
        if (iVar7 << 1 < 0) {
          iVar14 = iVar7 << 0x11;
          if (iVar4 == 0) {
            iVar14 = iVar7 << 0x10;
          }
          if (iVar14 < 0) goto _L0;
        }
        goto _L0;
      }
_L0:
      pnVar15 = (nwk_potential_parent_t *)(iVar6 + 0xb2c + iVar5);
      if (parent != (nwk_potential_parent_t *)0x0) {
        if (((uint)pnVar15->update_id != (uint)parent->update_id) &&
           (-1 < (int)(((uint)parent->update_id - (uint)pnVar15->update_id) * 0x1000000) >> 0x18))
        goto _L0;
      }
    }
    else {
_L0:
      pnVar15 = parent;
    }
    parent = pnVar15;
    uVar13 = uVar13 + 1 & 0xff;
  } while( true );
}

