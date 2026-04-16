/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_process_receive_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_process_receive_security(ezb_shortaddr_t src_shortaddr,zmsg_t *msg)

{
  undefined1 uVar1;
  uint16_t uVar2;
  short sVar3;
  undefined2 in_register_0000202a;
  int iVar4;
  ezb_err_t eVar5;
  int iVar6;
  short sVar7;
  byte bStack_3d;
  undefined1 auStack_3c [3];
  uint8_t ext_fcf;
  ezb_extaddr_t src_addr;
  aps_device_key_pair_t *key_pair;
  secur_aux_hdr_t aux_hdr;
  uint8_t aps_fcf;
  
  iVar4 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,1,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 6));
  uVar1 = aux_hdr.src_address.field_0.u8[6];
  uVar2 = aps_fcf_get_hdr_size(aux_hdr.src_address.field_0.u8[6]);
  if ((char)uVar1 < '\0') {
    sVar3 = zmsg_read_bytes(msg,uVar2,1,&bStack_3d);
    if ((bStack_3d & 3) == 1) {
      sVar7 = 1;
    }
    else if ((bStack_3d & 3) == 2) {
      sVar7 = 1;
    }
    else {
      sVar7 = 0;
    }
    uVar2 = uVar2 + sVar3 + sVar7;
  }
  zmsg_set_offset(msg,uVar2);
  if ((aux_hdr.src_address.field_0.u8[6] & 0x20) == 0) {
    eVar5 = 0;
  }
  else {
    msg->flags = msg->flags | 4;
    if (iVar4 == 0) {
      eVar5 = 0x13;
    }
    else {
      zmsg_read_bytes(msg,uVar2,0xe,&key_pair);
      if (((uint)key_pair & 0x20) == 0) {
        sVar3 = 5;
      }
      else {
        sVar3 = 0xd;
      }
      if (((uint)key_pair & 0x18) == 8) {
        sVar3 = sVar3 + 1;
      }
      if ((aux_hdr._0_4_ << 0x18 | (uint)key_pair >> 8) == 0xffffffff) {
        eVar5 = 0x13;
      }
      else {
        if (((uint)key_pair & 0x20) == 0) {
          iVar6 = nwk_address_extended_by_short
                            (CONCAT22(in_register_0000202a,src_shortaddr),auStack_3c);
          if (iVar6 != 0) {
            return iVar6;
          }
          aux_hdr.frame_cntr._0_1_ = (char)_auStack_3c;
          aux_hdr.frame_cntr._1_1_ = (char)((uint)_auStack_3c >> 8);
          aux_hdr.frame_cntr._2_1_ = (char)((uint)_auStack_3c >> 0x10);
          aux_hdr.src_address.field_0.u8[0] = (char)src_addr.field_0.u64._0_4_;
          aux_hdr.frame_cntr._3_1_ = (char)((uint)_auStack_3c >> 0x18);
          aux_hdr.src_address.field_0.u8[1] = (char)((uint)src_addr.field_0._0_4_ >> 8);
          aux_hdr.src_address.field_0.u8[2] = (char)((uint)src_addr.field_0._0_4_ >> 0x10);
          aux_hdr.src_address.field_0.u8[3] = (uint8_t)((uint)src_addr.field_0._0_4_ >> 0x18);
        }
        else {
          _auStack_3c = aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8;
          src_addr.field_0.u64._0_4_ =
               (uint)aux_hdr.src_address.field_0.u8[3] << 0x18 | (uint)aux_hdr._4_4_ >> 8;
        }
        key_pair = (aps_device_key_pair_t *)
                   CONCAT31(key_pair._1_3_,(byte)key_pair | (byte)iVar4 & 7);
        zmsg_write_bytes(msg,uVar2,1,&key_pair);
        zmsg_set_offset(msg,sVar3 + uVar2);
        src_addr.field_0.u64._4_4_ = aps_secur_get_key_pair_by_addr((ezb_extaddr_t *)auStack_3c);
        if ((aps_device_key_pair_t *)src_addr.field_0.u64._4_4_ == (aps_device_key_pair_t *)0x0) {
          eVar5 = 0x13;
        }
        else {
          eVar5 = aps_secur_unsecure_msg_by_key_pair
                            ((aps_device_key_pair_t *)src_addr.field_0.u64._4_4_,msg,
                             (secur_aux_hdr_t *)&key_pair);
          if (eVar5 == 0) {
            zmsg_add_footer(msg,(undefined1 *)((int)&src_addr.field_0 + 4),4);
          }
        }
      }
    }
  }
  return eVar5;
}

