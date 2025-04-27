-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 06, 2023 at 10:34 PM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `noddx`
--

-- --------------------------------------------------------

--
-- Table structure for table `assignments`
--

CREATE TABLE `assignments` (
  `id` int(11) NOT NULL,
  `name` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `assignments`
--

INSERT INTO `assignments` (`id`, `name`) VALUES
(0, 'Demo-Assignment#0: 6 questions');

-- --------------------------------------------------------

--
-- Table structure for table `entries01`
--

CREATE TABLE `entries01` (
  `id` int(11) NOT NULL,
  `submission_id` int(11) NOT NULL,
  `numline` int(11) NOT NULL,
  `sideleft` int(11) NOT NULL DEFAULT 0 COMMENT 'binary encoding of attribute set',
  `sideright` int(11) NOT NULL DEFAULT 0 COMMENT 'binary encoding of attribute set',
  `rule` int(11) NOT NULL DEFAULT 0 COMMENT 'enum for FD rules',
  `refs` text DEFAULT NULL COMMENT 'comma separated ints'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `entries01`
--

INSERT INTO `entries01` (`id`, `submission_id`, `numline`, `sideleft`, `sideright`, `rule`, `refs`) VALUES
(0, 1, 1, 2, 4, 0, '2'),
(1, 1, 2, 12, 17, 0, '4'),
(2, 1, 3, 12, 21, 3, '6'),
(3, 1, 4, 10, 21, 6, '5, 7'),
(4, 1, 5, 10, 5, 5, '8'),

(5, 2, 1, 12, 17, 0, '4'),
(6, 2, 2, 2, 4, 0, '2'),
(7, 2, 3, 12, 21, 3, '6'),
(8, 2, 4, 10, 21, 6, '6, 7'),

(9, 3, 1, 1, 2, 0, '1'),
(10, 3, 2, 12, 17, 0, '4'),
(11, 3, 3, 2, 4, 0, '2'),
(12, 3, 4, 1, 4, 2, '5, 6'),
(13, 3, 5, 12, 21, 3, '6'),
(14, 3, 6, 10, 21, 6, '7, 6'),
(15, 3, 7, 10, 6, 5, '10'),

(16, 4, 1, 1, 2, 0, '1'),
(17, 4, 2, 2, 4, 0, '2'),
(18, 4, 3, 1, 4, 2, '6, 5'),
(19, 4, 4, 1, 8, 0, '3'),
(20, 4, 5, 1, 12, 4, '7, 8'),
(21, 4, 6, 12, 17, 0, '4'),
(22, 4, 7, 12, 17, 0, '4'),
(23, 4, 8, 1, 17, 2, '9, 10'), -- Could also put psuedo transitivity here because that should work
(24, 4, 9, 1, 16, 5, '12'),

(25, 5, 1, 1, 2, 0, '1'),
(26, 5, 2, 2, 4, 0, '2'),
(27, 5, 3, 1, 8, 0, '3'),
(28, 5, 4, 12, 17, 0, '4'),
(29, 5, 5, 1, 16, 0, '1, 2, 3, 4'),

(30, 6, 1, 1, 2, 0, '1'),
(31, 6, 2, 2, 4, 0, '2'),
(32, 6, 3, 1, 8, 0, '3'),
(33, 6, 4, 12, 17, 0, '4'),
(34, 6, 5, 1, 4, 2, '5, 6'),
(35, 6, 6, 1, 12, 4, '7, 9'),
(36, 6, 7, 1, 17, 2, '8, 10'),
(37, 6, 8, 1, 16, 5, '11'),
(38, 6, 9, 3, 2, 3, '5'), -- this line is not the final answer line above it is so this proof should be incorrect

(39, 7, 1, 8, 16, 0, '3'),
(40, 7, 2, 16, 10, 0, '4'),
(41, 7, 3, 8, 10, 2, '5, 6'),
(42, 7, 4, 8, 2, 5, '7'),
(43, 7, 5, 8, 4, 0, '2'),
(44, 7, 6, 8, 6, 4, '8, 9'),
(45, 7, 7, 6, 1, 0, '1'),
(46, 7, 8, 8, 1, 2, '10, 11'),

(47, 8, 1, 8, 4, 0, '1'),
(48, 8, 2, 8, 16, 0, '2'),
(49, 8, 3, 8, 20, 4, '5, 6'),
(50, 8, 4, 10, 1, 6, '1, 7'),

(51, 9, 1, 10, 1, 6, '1, 2'),
(52, 9, 2, 16, 1, 2, '5, 4'),
(53, 9, 3, 8, 1, 2, '6, 3'), -- final answer but proof doesn't end
(54, 9, 4, 16, 2, 5, '4'),
(55, 9, 5, 8, 1, 0, '7'); -- final answer reiterated using given

-- --------------------------------------------------------

--
-- Table structure for table `entries02`
--

CREATE TABLE `entries02` (
  `id` int(11) NOT NULL,
  `submission_id` int(11) NOT NULL,
  `numline` int(11) NOT NULL,
  `list` int(11) NOT NULL DEFAULT 0 COMMENT 'binary encoding of set of attributes',
  `rule` int(11) DEFAULT NULL COMMENT 'enum for FD rules',
  `refs` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `entries02`
--

INSERT INTO `entries02` (`id`, `submission_id`, `numline`, `list`, `rule`, `refs`) VALUES
(0, 10, 1, 1, 1, ''),
(1, 10, 2, 3, 0, '1'),
(2, 10, 3, 7, 0, '2'),
(3, 10, 4, 15, 0, '3'),
(4, 10, 5, 31, 0, '4'),
(5, 10, 6, 31, 0, '1'),

(6, 11, 1, 1, 1, '1'), -- error here as reflxivity rule should not have a reference
(7, 11, 2, 3, 0, '1'),
(8, 11, 3, 7, 0, '2'),
(9, 11, 4, 15, 0, '3'),
(10, 11, 5, 31, 0, '4'),

(11, 12, 1, 1, 1, ''),
(12, 12, 2, 3, 0, '1'),
(13, 12, 3, 7, 0, '2'),
(14, 12, 4, 15, 0, '3'), -- this is not the final answer thats asked to be proved so incorrect

(15, 13, 1, 3, 1, ''),
(16, 13, 2, 7, 0, '1'),
(17, 13, 3, 15, 0, '2'),
(18, 13, 4, 15, 0, '1'),
(19, 13, 5, 31, 0, '3'), 

(20, 14, 1, 3, 1, ''),
(21, 14, 2, 7, 0, '1'),
(22, 14, 3, 15, 0, '2'),
(23, 14, 4, 15, 0, '1'),
(24, 14, 5, 15, 0, '4'), -- we do not have an attribute so fail and marked incorrect
(25, 14, 6, 31, 0, '3'),
(26, 14, 7, 63, 0, '4'),

(27, 15, 1, 3, 1, ''), 
(28, 15, 2, 7, 0, '1'),
(29, 15, 3, 15, 0, '2'),
(30, 15, 4, 31, 0, '3'), -- proof correct if stooped here
(31, 15, 5, 63, 0, '4'), -- can't determine F in this step so step wrong and proof incorrect

(32, 16, 1, 16, 1, ''),
(33, 16, 2, 24, 0, '2'),
(34, 16, 3, 25, 0, '1'),
(35, 16, 4, 29, 0, '3'),
(36, 16, 5, 29, 0, '4'),
(37, 16, 6, 29, 0, '2'),
(38, 16, 7, 61, 0, '5'),

(39, 17, 1, 17, 1, ''),  -- only given 1 of 2 attributes student put in list so inccorect because 2 are put here
(40, 17, 2, 17, 0, '1'),
(41, 17, 3, 25, 0, '2'),
(42, 17, 4, 29, 0, '3'),
(43, 17, 5, 61, 0, '4'),

(44, 18, 1, 16, 1, ''), 
(45, 18, 2, 24, 0, '2'), 
(46, 18, 3, 24, 0, '6'), -- references line number which isnt an FD which can't happen so incorrect
(47, 18, 4, 25, 0, '1'),
(48, 18, 5, 29, 0, '3'),
(49, 18, 6, 61, 0, '5');

-- --------------------------------------------------------

--
-- Table structure for table `qentries`
--

CREATE TABLE `qentries` (
  `id` int(11) NOT NULL,
  `question_id` int(11) NOT NULL,
  `numline` int(11) NOT NULL,
  `sideleft` int(11) NOT NULL DEFAULT 0,
  `sideright` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `qentries`
--

INSERT INTO `qentries` (`id`, `question_id`, `numline`, `sideleft`, `sideright`) VALUES
(0, 1, 1, 1, 2),
(1, 1, 2, 2, 4),
(2, 1, 3, 1, 8),
(3, 1, 4, 12, 17),

(4, 2, 1, 1, 2),
(5, 2, 2, 2, 4),
(6, 2, 3, 1, 8),
(7, 2, 4, 12, 17),

(8, 3, 1, 6, 1),
(9, 3, 2, 8, 4),
(10, 3, 3, 8, 16),
(11, 3, 4, 16, 10),

(12, 4, 1, 1, 2),
(13, 4, 2, 2, 4),
(14, 4, 3, 4, 8),
(15, 4, 4, 8, 16),

(20, 5, 1, 3, 4),
(21, 5, 2, 6, 9),
(22, 5, 3, 8, 16),
(23, 5, 4, 36, 2),

(25, 6, 1, 16, 1),
(26, 6, 2, 16, 8),
(27, 6, 3, 1, 4),
(28, 6, 4, 1, 8),
(29, 6, 5, 17, 32);

-- --------------------------------------------------------

--
-- Table structure for table `questions`
--

CREATE TABLE `questions` (
  `id` int(11) NOT NULL,
  `assignment_id` int(11) DEFAULT NULL,
  `name` text NOT NULL,
  `type` int(11) NOT NULL,
  `data1` int(11) DEFAULT NULL COMMENT 'auxiliary data, for LCoF this is final left, for AC this is the initial set ',
  `data2` int(11) DEFAULT NULL COMMENT 'For LCoF this is final right side.'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `questions`
--

INSERT INTO `questions` (`id`, `assignment_id`, `name`, `type`, `data1`, `data2`) VALUES
(1, 0, 'Consider the relational schema R(A,B,C,D,E) with the set F of functional dependencies\r\nF = {A->B, B->C, A->D, CD->AE}.\r\n\r\nShow the logical steps needed to prove\r\nBD->AC.', 1, 10, 5),
(2, 0, 'Consider the relational schema R(A,B,C,D,E) with the set F of functional dependencies\r\nF = {A->B, B->C, A->D, CD->AE}.\r\n\r\nShow the logical steps needed to prove\r\nA->E.', 1, 1, 16),
(3, 0, 'Consider the relational schema R(A,B,C,D,E) with the set F of functional dependencies\r\nF = {CB->A, D->C, D->E, E->BD}.\r\n\r\nShow the logical steps needed to prove\r\nD->A.', 1, 8, 1),
(4, 0, 'Consider the schema R=(A,B,C,D,E) with the set F of functional dependencies\r\nF={A->B, B->C, C->D, D->E}.\r\nFind the attribute closure {A}+\r\n', 2, 1, NULL),
(5, 0, 'Consider the schema R=(A,B,C,D,E,F) with the set F of functional dependencies\r\nF={AB->C, BC->AD, D->E,CF->B}.\r\nFind the attribute closure {A,B}+\r\n', 2, 3, NULL),
(6, 0, 'Consider the schema R=(A,B,C,D,E,F) with the set F of functional dependencies\r\nF={E->A, E->D, A->C, A->D, AE->F}.\r\n\r\nFind the attribute closure {E}+\r\n', 2, 16, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `submissions`
--

CREATE TABLE `submissions` (
  `id` int(11) NOT NULL,
  `timestamp` timestamp NOT NULL DEFAULT current_timestamp(),
  `question_id` int(11) DEFAULT NULL,
  `user_id` int(11) DEFAULT NULL,
  `feedback` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `submissions`
--

INSERT INTO `submissions` (`id`, `timestamp`, `question_id`, `user_id`, `feedback`) VALUES
(1, '2023-11-15 12:03:08', 1, NULL, NULL),
(2, '2023-11-16 12:03:08', 1, NULL, NULL),
(3, '2023-11-17 12:03:08', 1, NULL, NULL),
(4, '2023-11-15 12:03:08', 2, NULL, NULL),
(5, '2023-11-16 12:03:08', 2, NULL, NULL),
(6, '2023-11-17 12:03:08', 2, NULL, NULL),
(7, '2023-11-15 12:03:08', 3, NULL, NULL),
(8, '2023-11-16 12:03:08', 3, NULL, NULL),
(9, '2023-11-17 12:03:08', 3, NULL, NULL),
(10, '2023-11-15 12:03:08', 4, NULL, NULL),
(11, '2023-11-16 12:03:08', 4, NULL, NULL),
(12, '2023-11-17 12:03:08', 4, NULL, NULL),
(13, '2023-11-15 12:03:08', 5, NULL, NULL),
(14, '2023-11-16 12:03:08', 5, NULL, NULL),
(15, '2023-11-17 12:03:08', 5, NULL, NULL),
(16, '2023-11-15 12:03:08', 6, NULL, NULL),
(17, '2023-11-16 12:03:08', 6, NULL, NULL),
(18, '2023-11-17 12:03:08', 6, NULL, NULL);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `assignments`
--
ALTER TABLE `assignments`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `entries01`
--
ALTER TABLE `entries01`
  ADD PRIMARY KEY (`id`),
  ADD KEY `e1SID` (`submission_id`);

--
-- Indexes for table `entries02`
--
ALTER TABLE `entries02`
  ADD PRIMARY KEY (`id`),
  ADD KEY `e2SID` (`submission_id`);

--
-- Indexes for table `qentries`
--
ALTER TABLE `qentries`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `qeNumline` (`question_id`,`numline`),
  ADD KEY `qeQID` (`question_id`);

--
-- Indexes for table `questions`
--
ALTER TABLE `questions`
  ADD PRIMARY KEY (`id`),
  ADD KEY `Assignment-ID` (`assignment_id`);

--
-- Indexes for table `submissions`
--
ALTER TABLE `submissions`
  ADD PRIMARY KEY (`id`),
  ADD KEY `subQID` (`question_id`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `entries01`
--
ALTER TABLE `entries01`
  ADD CONSTRAINT `e1SID` FOREIGN KEY (`submission_id`) REFERENCES `submissions` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `entries02`
--
ALTER TABLE `entries02`
  ADD CONSTRAINT `e2SID` FOREIGN KEY (`submission_id`) REFERENCES `submissions` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `qentries`
--
ALTER TABLE `qentries`
  ADD CONSTRAINT `qeQID` FOREIGN KEY (`question_id`) REFERENCES `questions` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `questions`
--
ALTER TABLE `questions`
  ADD CONSTRAINT `Assignment-ID` FOREIGN KEY (`assignment_id`) REFERENCES `assignments` (`id`) ON DELETE SET NULL ON UPDATE CASCADE;

--
-- Constraints for table `submissions`
--
ALTER TABLE `submissions`
  ADD CONSTRAINT `subQID` FOREIGN KEY (`question_id`) REFERENCES `questions` (`id`) ON DELETE SET NULL ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
