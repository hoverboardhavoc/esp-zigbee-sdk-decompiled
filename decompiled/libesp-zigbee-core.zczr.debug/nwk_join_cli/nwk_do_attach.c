/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_do_attach
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_do_attach(nwk_join_req_t *req)

{
  byte bVar1;
  _Bool is_ed_capable;
  int iVar2;
  nwk_potential_parent_t *parent;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ezb_err_t eVar6;
  undefined1 uVar7;
  undefined4 uStack_3c;
  channel_page_t channel;
  undefined2 uStack_34;
  undefined2 uStack_32;
  byte bStack_30;
  byte bStack_2f;
  uint8_t uStack_2e;
  undefined2 uStack_2a;
  byte abStack_28 [2];
  ezb_panid_t panid;
  undefined2 auStack_22 [7];
  
  iVar2 = nwk_address_get_panid_ref();
  if (iVar2 == 0xff) {
    return 0x2c3;
  }
  is_ed_capable = (_Bool)nwk_is_device_zed();
  parent = nwk_choose_parent((nwk_panid_ref_t)iVar2,is_ed_capable,req->rejoin_network == '\0');
  if (parent == (nwk_potential_parent_t *)0x0) {
    return 0x2c3;
  }
  nwk_address_get_panid(iVar2,&uStack_2a);
  nwk_set_panid(uStack_2a);
  iVar2 = core_globals_get();
  *(nwk_potential_parent_t **)(iVar2 + 0xac4) = parent;
  bVar1 = req->rejoin_network;
  if (bVar1 == 0) {
    if ((int)parent->field_7 << 0x13 < 0) {
      bVar1 = 3;
_L0:
      uVar3 = nwk_get_short_address();
      if ((0xfff7 < uVar3) || (iVar2 = nwk_get_short_address(), iVar2 == 0)) {
        nwk_assign_shortaddr();
        nwk_set_short_address();
      }
      uVar4 = nwk_get_extended_address();
      uVar5 = nwk_get_short_address();
      auStack_22[0] = 0;
      iVar2 = nwk_address_update(uVar4,uVar5,auStack_22);
      if (iVar2 != 0) goto _L0;
      uStack_3c = 1 << ((uint)parent->field_7 & 0x1f) & 0x7ffffffU |
                  ((uint)parent->field_7 >> 7) << 0x1b;
      iVar2 = nwk_mm_set_pib_attr(0xff,0x61,&uStack_3c);
      if (iVar2 != 0) goto _L0;
      nwk_mm_set_pib_attr(0xff,0x4b,parent);
    }
_L0:
    iVar2 = core_globals_get();
    *(byte *)(iVar2 + 0xad3) = bVar1;
    if (bVar1 == 3) {
      eVar6 = nwk_send_network_comm_req(parent,'\0',false,req->capability_info);
      return eVar6;
    }
    if (bVar1 < 4) {
      if (bVar1 == 0) {
        if ((int)parent->field_7 << 2 < 0) {
          uVar7 = 2;
        }
        else {
          uVar7 = 3;
        }
        uStack_3c = CONCAT31(uStack_3c._1_3_,uVar7);
        channel.u32._0_2_ = (parent->addr).group_addr.bcast;
        channel.u32._2_2_ = *(undefined2 *)((int)&parent->addr + 4);
        uStack_34 = *(undefined2 *)((int)&parent->addr + 6);
        uStack_3c = CONCAT22((parent->addr).short_addr,(undefined2)uStack_3c);
        uStack_32 = uStack_2a;
        bStack_30 = (byte)((uint)parent->field_7 >> 7) & 0x1f;
        bStack_2f = SUB41(parent->field_7,0) & 0x7f;
        uStack_2e = req->capability_info;
        nwk_mm_asso_request(*(byte *)((int)&parent->field_7 + 3) & 0x1f,&uStack_3c);
        return 0;
      }
      if ((byte)(bVar1 - 1) < 2) {
        eVar6 = nwk_send_rejoin_req(parent,(_Bool)(req->field_0xa & 1),req->capability_info);
        return eVar6;
      }
      goto _L0;
    }
  }
  else {
    if (bVar1 == 2) {
      _abStack_28 = 0x5040201;
      bVar1 = abStack_28[((byte)req->field_0xa & 1) + ((uint)parent->field_7 >> 0xc & 1) * 2];
      if (bVar1 != 0) goto _L0;
      goto _L0;
    }
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_join_cli.c",199,"nwk_do_attach",&_LC1);
_L0:
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_join_cli.c",0xd5,"nwk_do_attach",
                  "(nwk_address_update(nwk_get_extended_address(), nwk_get_short_address(), &(nwk_addr_ref_t){0})) == 0"
                 );
_L0:
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_join_cli.c",0xdc,"nwk_do_attach",
                  "(nwk_mm_set_pib_attr(0xFF, 0x61U, &channel)) == 0");
  }
  if ((byte)(bVar1 - 4) < 2) {
    eVar6 = nwk_send_network_comm_req
                      (parent,'\x01',(_Bool)(req->field_0xa & 1),req->capability_info);
    return eVar6;
  }
_L0:
  __assert_func("//build/esp-zigbee/src/core/nwk/nwk_join_cli.c",0x106,"nwk_do_attach",&_LC1);
  return 0x2c3;
}

