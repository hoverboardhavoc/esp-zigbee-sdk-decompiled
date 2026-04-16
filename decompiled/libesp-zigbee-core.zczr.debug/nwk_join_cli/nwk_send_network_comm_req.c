/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_send_network_comm_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_send_network_comm_req
                    (nwk_potential_parent_t *parent,uint8_t comm_type,_Bool is_secur,
                    mac_cap_info_t mac_cap)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined3 in_register_00002031;
  uint8_t auStack_21 [9];
  
  if (CONCAT31(in_register_00002031,is_secur) == 0) {
    uVar1 = 0x21;
  }
  else {
    uVar1 = 0x2f;
  }
  iVar2 = zmsg_alloc(uVar1);
  if (iVar2 != 0) {
    zmsg_set_offset(0);
    uVar1 = nwk_get_short_address();
    nwk_frame_write_hdr(iVar2,uVar1,(parent->addr).short_addr,1,
                        CONCAT31(in_register_00002031,is_secur),0);
    iVar3 = core_globals_get();
    auStack_21[0] = *(uint8_t *)(iVar3 + 0x9d9);
    *(uint8_t *)(iVar3 + 0x9d9) = auStack_21[0] + '\x01';
    zmsg_write_bytes(iVar2,7,1,auStack_21);
    auStack_21[0] = '\x0e';
    zmsg_append_bytes(iVar2,1,auStack_21);
    auStack_21[0] = comm_type;
    zmsg_append_bytes(iVar2,1,auStack_21);
    auStack_21[0] = mac_cap;
    zmsg_append_bytes(iVar2,1,auStack_21);
    nwk_fwd_mac_data_req
              (iVar2,*(byte *)((int)&parent->field_7 + 3) & 0x1f,(parent->addr).short_addr,0);
  }
  return (uint)(iVar2 == 0);
}

