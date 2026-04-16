/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_write_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t mac_frame_write_hdr(uint8_t *buf,mac_addresses_t *addresses,mac_panids_t *panids,
                           mac_frame_version_t version,mac_frame_type_t type,mac_cmd_id_t cmd_id)

{
  int iVar1;
  byte bVar2;
  ezb_addr_mode_t eVar3;
  ezb_shortaddr_t eVar4;
  ezb_shortaddr_t eVar5;
  ezb_grpaddr_t eVar6;
  uint16_t fcf;
  uint uVar7;
  uint uVar8;
  ezb_grpaddr_t *peVar9;
  _Bool _Var10;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar11;
  
  eVar4 = panids->source;
  eVar5 = panids->destination;
  bVar2 = (addresses->destination).addr_mode;
  uVar11 = (uint)(addresses->source).addr_mode;
  uVar7 = (int)(short)((ushort)bVar2 << 10 | (ushort)type | (ushort)version) | uVar11 << 0xe;
  uVar8 = uVar7 & 0xffff;
  if ((bVar2 != 0) &&
     (((bVar2 != 2 || ((addresses->destination).u.short_addr != 0xffff)) && (type != MAC_FRAME_ACK))
     )) {
    uVar8 = uVar7 & 0xffff | 0x20;
  }
  if (version != MAC_FRAME_VERSION_2006) {
    if (version == MAC_FRAME_VERSION_2015) {
      if ((bVar2 == 0) || (uVar11 == 0)) {
        if ((bVar2 == 0) && (uVar11 == 0)) {
          uVar8 = uVar8 | 0x40;
        }
      }
      else if (((bVar2 == 2) || (uVar11 == 2)) && (eVar4 == eVar5)) {
        uVar8 = uVar8 | 0x40;
      }
      goto _L0;
    }
    if (version != MAC_FRAME_VERSION_2003) goto _L0;
  }
  if (((uVar11 != 0) && (bVar2 != 0)) && (eVar4 == eVar5)) {
    uVar8 = uVar8 | 0x40;
  }
_L0:
  fcf = (uint16_t)uVar8;
  *(uint16_t *)buf = fcf;
  iVar1 = 2;
  if ((uVar8 & 0x100) == 0) {
    iVar1 = 3;
  }
  peVar9 = (ezb_grpaddr_t *)(buf + iVar1);
  _Var10 = mac_fcf_has_dst_panid(fcf);
  if (CONCAT31(extraout_var,_Var10) != 0) {
    peVar9->group = eVar5;
    peVar9 = (ezb_grpaddr_t *)&peVar9->bcast;
  }
  eVar3 = (addresses->destination).addr_mode;
  if (eVar3 == '\x02') {
    peVar9->group = (addresses->destination).u.short_addr;
    peVar9 = (ezb_grpaddr_t *)&peVar9->bcast;
  }
  else if (eVar3 == '\x03') {
    eVar6 = *(ezb_grpaddr_t *)((int)&(addresses->destination).u + 4);
    *peVar9 = (addresses->destination).u.group_addr;
    peVar9[1] = eVar6;
    peVar9 = peVar9 + 2;
  }
  _Var10 = mac_fcf_has_src_panid(fcf);
  if (CONCAT31(extraout_var_00,_Var10) != 0) {
    peVar9->group = eVar4;
    peVar9 = (ezb_grpaddr_t *)&peVar9->bcast;
  }
  eVar3 = (addresses->source).addr_mode;
  if (eVar3 == '\x02') {
    peVar9->group = (addresses->source).u.short_addr;
    peVar9 = (ezb_grpaddr_t *)&peVar9->bcast;
  }
  else if (eVar3 == '\x03') {
    eVar6 = *(ezb_grpaddr_t *)((int)&(addresses->source).u + 4);
    *peVar9 = (addresses->source).u.group_addr;
    peVar9[1] = eVar6;
    peVar9 = peVar9 + 2;
  }
  if (type == MAC_FRAME_CMD) {
    *(mac_cmd_id_t *)&peVar9->group = cmd_id;
    peVar9 = (ezb_grpaddr_t *)((int)&peVar9->group + 1);
  }
  return (char)peVar9 - (char)buf;
}

