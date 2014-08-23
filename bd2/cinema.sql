SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL';

CREATE SCHEMA IF NOT EXISTS `Cinema` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci ;
USE `Cinema` ;

-- -----------------------------------------------------
-- Table `Cinema`.`Cinema`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `Cinema`.`Cinema` (
  `idCinema` INT NOT NULL ,
  `nomecinema` VARCHAR(45) NULL ,
  `capacidade` INT(11) NULL ,
  `endereco` VARCHAR(45) NULL ,
  PRIMARY KEY (`idCinema`) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Cinema`.`Filme`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `Cinema`.`Filme` (
  `idFilme` INT NOT NULL ,
  `titulo_original` VARCHAR(45) NULL ,
  `dataproducao` VARCHAR(45) NULL ,
  `ano` VARCHAR(45) NULL ,
  PRIMARY KEY (`idFilme`) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Cinema`.`SalaExibicao`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `Cinema`.`SalaExibicao` (
  `SalaExibicao` INT NOT NULL ,
  `nomesala` VARCHAR(45) NULL ,
  `quant_lugares` VARCHAR(45) NULL ,
  `Cinema_idCinema` INT NOT NULL ,
  PRIMARY KEY (`SalaExibicao`, `Cinema_idCinema`) ,
  INDEX `fk_SalaExibicao_Cinema1` (`Cinema_idCinema` ASC) ,
  CONSTRAINT `fk_SalaExibicao_Cinema1`
    FOREIGN KEY (`Cinema_idCinema` )
    REFERENCES `Cinema`.`Cinema` (`idCinema` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Cinema`.`Cinema_has_Filme`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `Cinema`.`Cinema_has_Filme` (
  `Cinema_idCinema` INT NOT NULL ,
  `Filme_idFilme` INT NOT NULL ,
  `periodoexibicao` VARCHAR(45) NULL ,
  PRIMARY KEY (`Cinema_idCinema`, `Filme_idFilme`) ,
  INDEX `fk_Cinema_has_Filme_Filme1` (`Filme_idFilme` ASC) ,
  INDEX `fk_Cinema_has_Filme_Cinema1` (`Cinema_idCinema` ASC) ,
  CONSTRAINT `fk_Cinema_has_Filme_Cinema1`
    FOREIGN KEY (`Cinema_idCinema` )
    REFERENCES `Cinema`.`Cinema` (`idCinema` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Cinema_has_Filme_Filme1`
    FOREIGN KEY (`Filme_idFilme` )
    REFERENCES `Cinema`.`Filme` (`idFilme` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;



SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
