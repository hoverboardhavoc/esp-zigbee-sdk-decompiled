/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_write_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t mac_frame_write_hdr(uint8_t *buf,mac_addresses_t *addresses,mac_panids_t *panids,
                           mac_frame_version_t version,mac_frame_type_t type,mac_cmd_id_t cmd_id)

{
  ezb_shortaddr_t eVar1;
  ezb_shortaddr_t eVar2;
  bool bVar3;
  ezb_grpaddr_t eVar4;
  ezb_grpaddr_t *peVar5;
  ezb_grpaddr_t *peVar6;
  uint16_t fcf;
  mac_frame_version_t mVar7;
  mac_frame_version_t mVar8;
  _Bool _Var9;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar10;
  uint uVar11;
  
  uVar10 = (uint)(addresses->destination).addr_mode;
  uVar11 = (uint)(addresses->source).addr_mode;
  mVar7 = uVar10 << 10 | uVar11 << 0xe | type | version;
  eVar1 = panids->source;
  eVar2 = panids->destination;
  mVar8 = mVar7 & 0xffff;
  if (uVar10 == 0) {
    if (((version != MAC_FRAME_VERSION_2006) && (version == MAC_FRAME_VERSION_2015)) &&
       (uVar11 == 0)) {
      mVar8 = mVar7 & 0xffff | 0x40;
    }
    goto _L0;
  }
  if (((uVar10 != 2) || ((addresses->destination).u.short_addr != 0xffff)) &&
     (type != MAC_FRAME_ACK)) {
    mVar8 = mVar7 & 0xffff | 0x20;
  }
  if (version == MAC_FRAME_VERSION_2006) {
_L0:
    if (uVar11 == 0) goto _L0;
  }
  else {
    if (version != MAC_FRAME_VERSION_2015) {
      if (version != MAC_FRAME_VERSION_2003) goto _L0;
      goto _L0;
    }
    if ((uVar11 == 0) || ((uVar10 != 2 && (uVar11 != 2)))) goto _L0;
  }
  if (eVar1 == eVar2) {
    mVar8 = mVar8 | 0x40;
  }
_L0:
  bVar3 = (mVar8 & 0x100) == MAC_FRAME_VERSION_2003;
  fcf = (uint16_t)mVar8;
  *(uint16_t *)buf = fcf;
  peVar5 = (ezb_grpaddr_t *)(buf + bVar3 + 2);
  _Var9 = mac_fcf_has_dst_panid(fcf);
  if (CONCAT31(extraout_var,_Var9) != 0) {
    peVar5->group = eVar2;
    peVar5 = (ezb_grpaddr_t *)(buf + bVar3 + 4);
  }
  if (uVar10 == 2) {
    peVar6 = (ezb_grpaddr_t *)&peVar5->bcast;
    peVar5->group = (addresses->destination).u.short_addr;
  }
  else {
    peVar6 = peVar5;
    if (uVar10 == 3) {
      eVar4 = *(ezb_grpaddr_t *)((int)&(addresses->destination).u + 4);
      *peVar5 = (addresses->destination).u.group_addr;
      peVar5[1] = eVar4;
      peVar6 = peVar5 + 2;
    }
  }
  _Var9 = mac_fcf_has_src_panid(fcf);
  if (CONCAT31(extraout_var_00,_Var9) != 0) {
    peVar6->group = eVar1;
    peVar6 = (ezb_grpaddr_t *)&peVar6->bcast;
  }
  if (uVar11 == 2) {
    peVar5 = (ezb_grpaddr_t *)&peVar6->bcast;
    peVar6->group = (addresses->source).u.short_addr;
  }
  else {
    peVar5 = peVar6;
    if (uVar11 == 3) {
      eVar4 = *(ezb_grpaddr_t *)((int)&(addresses->source).u + 4);
      *peVar6 = (addresses->source).u.group_addr;
      peVar6[1] = eVar4;
      peVar5 = peVar6 + 2;
    }
  }
  if (type == MAC_FRAME_CMD) {
    *(mac_cmd_id_t *)&peVar5->group = cmd_id;
    peVar5 = (ezb_grpaddr_t *)((int)&peVar5->group + 1);
  }
  return (char)peVar5 - (char)buf;
}

