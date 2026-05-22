/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_verify_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_cmd_handle_verify_key(aps_header_t *aps_hdr,zmsg_t *msg)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  undefined1 auStack_60 [4];
  uint8_t hash [16];
  apsme_verify_key_ind_t ind;
  uint8_t uStack_33;
  uint8_t uStack_32;
  uint8_t uStack_31;
  
  if ((aps_hdr->addr_info).dst_addr < 0xfff8) {
    hash[0xc] = '\0';
    hash[0xd] = '\0';
    hash[0xe] = '\0';
    hash[0xf] = '\0';
    ind.src_address.field_0.u64._0_4_ = 0;
    ind.src_address.field_0.u64._4_4_ = 0;
    ind._8_4_ = 0;
    ind.field_2._3_4_ = 0;
    ind.field_2._7_4_ = 0;
    ind.field_2.initiator_hash[0xb] = '\0';
    iVar1 = zmsg_get_offset(msg);
    uVar2 = iVar1 + 1U & 0xffff;
    iVar1 = zmsg_get_length(msg);
    if ((int)(iVar1 - uVar2) < 0x19) {
      iVar1 = 0x10;
    }
    else {
      iVar1 = zmsg_read_bytes(msg,uVar2,1,(undefined1 *)((int)&ind.src_address.field_0 + 4));
      uVar2 = uVar2 + iVar1 & 0xffff;
      iVar1 = zmsg_read_bytes(msg,uVar2,8,hash + 0xc);
      if ((ind.src_address.field_0.u64._4_4_ & 0xff) == 3) {
        iVar1 = aps_secur_is_tc();
        if (iVar1 != 0) {
          iVar1 = 0;
          goto _L0;
        }
        iVar1 = aps_secur_is_addr_tc(hash + 0xc);
        if (iVar1 != 0) {
          iVar1 = 0;
          goto _L0;
        }
      }
      else if ((ind.src_address.field_0.u64._4_4_ & 0xff) == 4) {
        iVar3 = aps_secur_is_tc();
        if (iVar3 == 0) {
          iVar1 = 0;
        }
        else {
          iVar3 = aps_secur_get_key_pair_by_addr(hash + 0xc);
          if (iVar3 == 0) {
            iVar1 = 0;
          }
          else {
            uVar4 = *(ushort *)(iVar3 + 0x34) & 6;
            if ((uVar4 == 2) || (uVar4 == 4)) {
              aps_secur_key_pair_get_hash(iVar3,auStack_60);
              iVar1 = zmsg_compare_bytes(msg,uVar2 + iVar1 & 0xffff,auStack_60,0x10);
              if (iVar1 == 0) {
                iVar1 = 0;
              }
              else {
                if ((*(ushort *)(iVar3 + 0x34) & 6) == 2) {
                  aps_secur_key_pair_set_verified(iVar3);
                }
                apsme_verify_key_indication((apsme_verify_key_ind_t *)(hash + 0xc));
                iVar1 = 0;
              }
            }
            else {
              iVar1 = 0;
            }
          }
        }
        goto _L0;
      }
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0x12;
  }
_L0:
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  if (iVar1 == 0) {
    ind.field_2._15_1_ = hash[0xc];
    uStack_33 = hash[0xd];
    uStack_32 = hash[0xe];
    uStack_31 = hash[0xf];
    apsme_confirm_key_request((apsme_confirm_key_req_t *)((int)&ind.field_2 + 0xf));
  }
  return;
}

